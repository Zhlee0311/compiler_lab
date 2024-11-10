#ifndef __GRAMMAR_HPP
#define __GRAMMAR_HPP

#include <unordered_map>
#include <unordered_set>
#include <string>

class Grammar
{
private:
    static std::unordered_map<std::string, std::unordered_set<std::string>> grammar;

public:
    static void clearGrammar();
    static void readGrammar();
    static void printGrammar();
    static std::unordered_map<std::string, std::unordered_set<std::string>> getGrammar();
    static void elr();

private:
    static void elrDirect(const std::string &non_terminal);
};

#endif