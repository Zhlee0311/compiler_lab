#ifndef __GRAMMAR_HPP
#define __GRAMMAR_HPP

#include <unordered_map>
#include <unordered_set>
#include <string>

class Grammar
{
public:
    static std::unordered_map<std::string, std::unordered_set<std::string>> grammar;
    static void clearGrammar();
    static void readGrammar();
    static void printGrammar();
    static void elr();

private:
    static void elrDirect(const std::string &non_terminal);
};

#endif