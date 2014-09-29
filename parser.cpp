#include "parser.h"
#include <map>

using namespace std;

// TODO: the tree will be parsed from JSON and should be type_t


void BuildExpressionsTree(Expression &root){

//    ExpressionType help = new Expression("Help", RegexRules("", "", ""));
//    ExpressionType argument("Argument", RegexRules("", "", ""));

//    ExpressionType command = new Expression("Command", RegexRules("", "", ""));
//    command.AddNested(argument);

//    ExpressionType expression = new Expression("Expression", RegexRules("", "", ""));
//    expression.AddNested(command).AddNested(help);

//    ExpressionType labeled = new Expression("Labeled", RegexRules("^[A-Z]+[\sA-Z]*\n", "", ""));
//    labeled.AddNested(expression);

//    ExpressionType group = new Expression("Group", RegexRules("^[A-Z]+[\sA-Z]*\n", "", ""));
//    group.AddNested(labeled).AddNested(group).AddNested(expression);

//    root.AddNested(new Expression("Group", RegexRules("^[A-Z]+[\sA-Z]*\n", "", "")));
}



// parse from 'position', recursively collecting children
// increment position to the end of this Expression
// return true if this Expression was found in 'position'
bool Expression::Parse(ParsingPos &position, const ParsingPos &end)
{
    string::iterator start = position;
    if(IsStart(position, end))
    {
        do {
            for(int i=0; i< m_nestedExpressions.size(); i++) {
                auto nested = m_nestedExpressions[i];
                // let nested a chance to consume parts of this expression
                bool consumed = nested->Parse(position, end);
                if(consumed) {

                    // key is name + index,e.g "Argument0", "Argument1"
                    QString key = nested->name;
                    key.append(std::to_string(i).c_str());

                    // create an instance of this expression
                    // swap the properties to avoid deep copy
                    //insert(expression, Expression)
                    (*this)[key]->swap(*nested);
                    (*this)[key]->props.swap(nested->props);
                }
            }
            position++;
        } while(!IsEnd(position, end));

        // terminal expression?
        if(m_nestedExpressions.empty()) {

            //TODO: here we may extract explicit data types
            props["data"] = string (start, position).c_str();
        }
        return true;
    }
    return false;
}

// tell if this expression starts at 'position'
bool Expression::IsStart(const ParsingPos &position, const ParsingPos &end) {

    // REVIEW: I hope it's shallow, is it?
    return regex_match(string().assign(position, end), m_rules.m_start);
}

// tell if this is the end of the expression
bool Expression::IsEnd(const ParsingPos &position, const ParsingPos &end) {
    // REVIEW: I hope it's shallow, is it?
    return regex_match(string().assign(position, end), m_rules.m_end);
}

