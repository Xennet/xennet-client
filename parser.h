#ifndef PARSER_H
#define PARSER_H

#include "model.h"
#include <string>
#include <vector>
#include <regex>
#include <boost/shared_ptr.hpp>

class Expression;

// TODO: this should actually also be type_t:)
typedef boost::shared_ptr<Expression> ExpressionType;
typedef std::vector<ExpressionType> Expressions;
typedef std::string::iterator ParsingPos;

class RegexRules{
public:
    RegexRules(const char* start, const char* end, const char* match)
        :m_start(start), m_end(end), m_match(match){}
    std::regex m_match; // whole expression match (greedy), use only for atoms!
    std::regex m_start; // position is expression start (lazy)
    std::regex m_end;   // position is expression end (lazy)
};

class Expression : public type_t
{
    Expressions m_nestedExpressions;
    RegexRules m_rules;
public:

    Expression(const char *name, RegexRules &rules)
        :type_t(name), m_rules(rules){
    }

    // parse from 'position', recursively collecting children
    // increment position to the end of this Expression
    // return true if this Expression was found in 'position'
    bool Parse(ParsingPos &position, const ParsingPos &end);

    // tell if this expression starts at 'position'
    virtual bool IsStart(const ParsingPos &position, const ParsingPos &end);

    // tell if this is the end of the expression
    virtual bool IsEnd(const ParsingPos &position, const ParsingPos &end);

    Expression& AddNested(ExpressionType nested){
        m_nestedExpressions.push_back(nested);
        return *this;
    }
};

#endif // PARSER_H
