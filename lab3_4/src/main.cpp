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
    Grammar::readGrammar();
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
            Grammar::exlp();
            Grammar::elr();
            break;
        }
        if (Grammar::isLL1())
        {
            std::cout << "\033[32m" << "改造后的文法是LL(1)文法" << "\033[0m" << std::endl;
        }
        else
        {
            std::cout << "\033[31m" << "改造后的文法仍非LL(1)文法" << "\033[0m" << std::endl;
        }
    }


    Grammar::printGrammar();


    std::cout << "Nterminal: ";
    for (const auto &nt : Grammar::nterminal)
    {
        std::cout << nt << ", ";
    }
    std::cout << std::endl;

    std::cout << "Terminal: ";
    for (const auto &t : Grammar::terminal)
    {
        std::cout << t << ", ";
    }
    std::cout << std::endl;


    std::string test = "E'";
    auto first = Grammar::firstGet(test);
    auto follow = Grammar::followGet(test);
    std::cout << "First: ";
    for (const auto &f : first)
    {
        std::cout << f << ", ";
    }
    std::cout << std::endl;

    std::cout << "Follow: ";
    for (const auto &f : follow)
    {
        std::cout << f << ", ";
    }
    std::cout << std::endl;


    std::cout << "Select: ";
    auto grammar = Grammar::getGrammar();
    for(const auto & [left,rights]:grammar){
        for(const auto &right:rights){
            auto select = Grammar::selectGet(left,right);
            for(const auto &s:select){
                std::cout << left << " -> " << right << " : " << s << std::endl;
            }
        }
        std::cout << std::endl;
    }

    std::string sentence;
    std::cout << "\033[33m" << "请输入1个待分析的句子: " << "\033[0m" << std::endl;
    std::cin >> sentence;


    Grammar::parseLL1(sentence);
    Grammar::clearGrammar();
    return 0;
}