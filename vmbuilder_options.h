#ifndef VMBUILDER_OPTIONS_H
#define VMBUILDER_OPTIONS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <regex>
#include <list>
#include <algorithm>

#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>


struct Option {
    std::string name, valType, defaultValue, help;
};

class Options{
    std::vector<Option> m_records;
    void extractDefaultValue(const std::string &help, std::string &def);
public:
    Options(){}
    std::vector<Option> parse(std::ifstream in);
    void dumpJson(std::ofstream &out);
};

#endif // VMBUILDER_OPTIONS_H
