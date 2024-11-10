#include <iostream>
#include "grammar.hpp"

std::unordered_map<std::string, std::unordered_set<std::string>> Grammar::grammar;

int main()
{   
    while (true)
    {
        Grammar::readGrammar();

        if (!Grammar::getGrammar().empty())
        {
            std::cout << "转换前的文法:" << std::endl;
            Grammar::printGrammar();
            Grammar::elr();
            std::cout << "转换后的文法:" << std::endl;
            Grammar::printGrammar();
        }

        Grammar::clearGrammar();

        std::cout << "是否继续处理另一个文件？(y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
    }
    return 0;
}