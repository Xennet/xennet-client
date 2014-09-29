#include "vmbuilder_options.h"

using namespace std;

typedef boost::char_separator<char> Delimiter;
typedef boost::tokenizer<Delimiter> Tok;

const char *leading_space = "                        ";
const int leading_space_len = strlen(leading_space);

void Options::dumpJson(ofstream &out) {
    stringstream json;
    for(auto opt : m_records){
        boost::replace_all(opt.help, "'", "\\'");
        json << "[";
        if(!opt.name.empty()) {
            json << "'opt':'" << opt.name << "',";
            if(!opt.valType.empty())
                json << "'type':'" << opt.valType << "',";
            if(!opt.defaultValue.empty())
                json << "'def':'" << opt.defaultValue << "',";
        }
        json << "'help':'" << opt.help << "'";
        json << "]\n";
    }

    out << json.str();
}

void Options::extractDefaultValue(const string &help, string &def) {
    smatch m;
    if(regex_search(help, m, regex("\\[default:\\s(.+)\\]$")))
    {
        if(m.size()>1)
            def = m[1];
    }
}

std::vector<Option> Options::parse(ifstream in) {

    // NOTE: must have two spaces before comment. this will fail: "-x The comment",
    string str((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    Tok t(str, Delimiter("\n"));
    int iPrevOpt = -1;

    for(auto line : t) {
        // line with only help text ?
        if(line.compare(0, leading_space_len, leading_space, leading_space_len) == 0) {
            if(iPrevOpt >=0)
                m_records[iPrevOpt].help += " " + line.substr(leading_space_len, line.size()-1);
        }
        // line containing options or group title
        else {
            // finalize previous option
            if(iPrevOpt >=0)
                extractDefaultValue(m_records[iPrevOpt].help, m_records[iPrevOpt].defaultValue);

            // see if it's group description, e.g "  Build options:" or "  Disk:"
            if(regex_match(line, regex("^[a-zA-Z\\s]+:$"))) {
                Option opt;
                opt.help = line;
                m_records.push_back(opt);
            }
            // line with options, e.g: "-v, --verbose       Show progress information"
            else {
                Option opt;
                int optStart = line.find_first_of('-');
                if(optStart != line.npos) {
                    line = line.substr(optStart);
                    size_t helpStart = line.find("  ");
                    string options = line.substr(0, helpStart);
                    if(helpStart != line.npos)
                        opt.help = line.substr(line.find_first_not_of(' ', helpStart));

                    // split options and take only the first
                    Tok t2(options, Delimiter(","));
                    Tok::iterator it2 = t2.begin();
                    if(it2 != t2.end()) {
                        string nameValue = *it2;

                        // may be 'name', 'name=value', or 'name value',e.g "-c CONFIG" "--config=CONFIG"
                        Tok t3(nameValue, Delimiter(" ="));
                        Tok::iterator it3 = t3.begin();
                        if(it3 != t3.end())
                            opt.name = *it3;
                        if(++it3 != t3.end())
                            opt.valType = *it3;
                    }
                    m_records.push_back(opt);
                    iPrevOpt = m_records.size()-1;
                }
            }
        }
    }
    return m_records;
}
