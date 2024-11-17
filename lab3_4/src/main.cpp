#include <iostream>
#include "grammar.hpp"

std::unordered_map<std::string, std::unordered_set<std::string>> Grammar::grammar;
std::unordered_map<std::string, std::unordered_set<std::string>> Grammar::firstSets;
std::unordered_map<std::string, std::unordered_set<std::string>> Grammar::followSets;
std::unordered_set<std::string> Grammar::nterminal;
std::unordered_set<std::string> Grammar::terminal;
std::unordered_set<std::string> Grammar::epsilons;
const std::string Grammar::epsilon = "ε";
std::string Grammar::start;

int main()
{
    while (true)
    {
        bool flag = true;
        Grammar::readGrammar();
        std::cout << "\033[33m" << "读入的文法为: " << "\033[0m" << std::endl;
        Grammar::printGrammar();
        if (Grammar::isLL1())
        {
            std::cout << "\033[32m" << "该文法是LL(1)文法" << "\033[0m" << std::endl;
        }
        else
        {
            std::cout << "\033[33m" << "该文法非LL(1)文法，是否进行改造: " << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "1. 提取左公因子" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "2. 消除左递归" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "3. 提取左公因子并消除左递归" << "\033[0m" << std::endl;
            int choice;
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                Grammar::exlp();
                break;
            case 2:
                Grammar::elr();
                break;
            case 3:
            {
                Grammar::exlp();
                Grammar::elr();
                break;
            }
            }
            std::cout << "\033[33m" << "改造后的文法为: " << "\033[0m" << std::endl;
            Grammar::printGrammar();
            if (Grammar::isLL1())
            {
                std::cout << "\033[32m" << "改造后的文法是LL(1)文法" << "\033[0m" << std::endl;
            }
            else
            {
                std::cout << "\033[31m" << "改造后的文法仍非LL(1)文法" << "\033[0m" << std::endl;
                flag = false;
            }
        }
        while (true && flag)
        {
            std::cout << "\033[33m" << "请输入1个待分析的句子: " << "\033[0m" << std::endl;
            std::string sentence;
            std::cin >> sentence;
            std::cout << "=================================" << std::endl;
            std::cout << "\033[35m" << "Start Parsing: " << sentence << "\033[0m" << std::endl;
            Grammar::parseLL1(sentence);
            std::cout << "=================================" << std::endl;

            std::cout << "\033[33m" << "是否继续分析句子(y/n): " << "\033[0m" << std::endl;
            char next;
            std::cin >> next;
            if (next == 'n')
            {
                break;
            }
        }
        std::cout << "\033[33m" << "是否读入另一个文法(y/n): " << "\033[0m" << std::endl;
        char next;
        std::cin >> next;
        if (next == 'n')
        {
            break;
        }
    }
}