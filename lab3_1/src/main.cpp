#include <iostream>
#include "grammar.hpp"

std::unordered_map<std::string, std::unordered_set<std::string>> Grammar::grammar;

int main()
{
    Grammar::readGrammar();
    if (!Grammar::grammar.empty())
    {
        std::cout << "转换前的文法:" << std::endl;
        Grammar::printGrammar();
        Grammar::elr();
        std::cout << "转换后的文法:" << std::endl;
        Grammar::printGrammar();
    }
    return 0;
}