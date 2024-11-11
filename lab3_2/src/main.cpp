#include <iostream>
#include "grammar.hpp"

std::unordered_map<std::string, std::unordered_set<std::string>> Grammar::grammar;
std::unordered_set<std::string> Grammar::nterminal;
std::unordered_set<std::string> Grammar::terminal;
const std::string Grammar::epsilon = "ε";

int main()
{
    while (true)
    {
        Grammar::readGrammar();

        if (!Grammar::getGrammar().empty())
        {
            while (true)
            {
                std::cout << "\033[33m" << "请选择操作: " << "\033[0m" << std::endl;
                std::cout << "\033[35m" << "1. 消除左递归" << "\033[0m" << std::endl;
                std::cout << "\033[35m" << "2. 提取左公因子" << "\033[0m" << std::endl;
                std::cout << "\033[35m" << "3. 消除左递归 + 提取左公因子" << "\033[0m" << std::endl;

                int option;
                while (!(std::cin >> option))
                {
                    std::cin.clear();                                                   // 清除错误标志
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略错误输入
                    std::cout << "\033[31m" << "无效的输入，请输入一个数字" << "\033[0m" << std::endl;
                }

                auto print = []() -> void
                {
                    std::cout << "转换前的文法:" << std::endl;
                    Grammar::printGrammar();
                };

                switch (option)
                {
                case 1:
                {
                    print();
                    Grammar::elr();
                    break;
                }
                case 2:
                {
                    print();
                    Grammar::exlp();
                    break;
                }
                case 3:
                {
                    print();
                    Grammar::elr();
                    Grammar::exlp();
                    break;
                }
                default:
                    std::cout << "\033[31m" << "无效的选项，请重新输入" << "\033[0m" << std::endl;
                    continue;
                }
                break;
            }

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