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
    std::string input;
    while (true)
    {
        Grammar::readGrammar();
        if (Grammar::empty())
        {
            std::cout << "\033[33m" << "是否继续查询其他文法？(y/n)" << "\033[0m" << std::endl;
            char choice;
            std::cin >> choice;
            if (choice == 'n')
            {
                break;
            }else{
                continue;
            }
        }
        Grammar::printGrammar();

        while (true)
        {
            std::cout << "\033[33m" << "输入待查询的文法符号: " << "\033[0m" << std::endl;
            std::cin >> input;

            auto res1 = Grammar::firstGet(input);
            auto res2 = Grammar::followGet(input);


            std::cout << "\033[36m" << "First(" << input << ") = {";
            for (auto it = res1.begin(); it != res1.end(); ++it)
            {
                std::cout << *it;
                if (std::next(it) != res1.end())
                { // 检查是否是最后一个元素
                    std::cout << ", ";
                }
            }
            std::cout << "}" << "\033[0m" << std::endl;

            std::cout << "\033[32m" << "Follow(" << input << ") = {";
            for (auto it = res2.begin(); it != res2.end(); ++it)
            {
                std::cout << *it;
                if (std::next(it) != res2.end())
                { // 检查是否是最后一个元素
                    std::cout << ", ";
                }
            }
            std::cout << "}" << "\033[0m" << std::endl;


            std::cout << "\033[33m" << "是否继续查询该文法的符号？(y/n)" << "\033[0m" << std::endl;
            char choice;
            std::cin >> choice;
            if (choice == 'n')
            {
                break;
            }
        }

        Grammar::clearGrammar();
        std::cout << "\033[33m" << "是否继续查询其他文法？(y/n)" << "\033[0m" << std::endl;
        char choice;
        std::cin >> choice;
        if (choice == 'n')
        {
            break;
        }
    }

    return 0;
}