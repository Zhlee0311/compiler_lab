#include "grammar.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

void Grammar::clearGrammar()
{
    grammar.clear();
}

void Grammar::readGrammar()
{
    std::string filename;
    std::cout << "请输入1个文法文件的名称: " << std::endl;
    std::cin >> filename;
    // 检查文件名是否以".txt"结尾，如果没有则补上
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt")
    {
        filename += ".txt";
    }
    std::string path = fs::current_path().parent_path().string() + "/grammar/" + filename;

    // 检查文件是否存在
    if (!fs::exists(path))
    {
        std::cout << "\033[31m" << "文件不存在: " << "\033[0m" << "\033[34m" << path << "\033[0m" << std::endl;
        return;
    }
    // 打开文件
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cout << "\033[31m" << "文件打开失败: " << "\033[0m" << "\033[34m" << path << "\033[0m" << std::endl;
        return;
    }
    // 读取文件
    std::string line;
    while (std::getline(file, line))
    {
        // 去掉空白字符
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        // 忽略空行
        if (line.empty())
        {
            continue;
        }
        // "->" 分割左右部
        size_t pos = line.find("->");
        if (pos != std::string::npos)
        {
            std::string non_terminal = line.substr(0, pos); // 非终结符
            std::string rights = line.substr(pos + 2);      // 产生式右部
            size_t start = 0;
            size_t end = rights.find("|");
            while (end != std::string::npos)
            {
                grammar[non_terminal].insert(rights.substr(start, end - start));
                start = end + 1;
                end = rights.find("|", start);
            }
            grammar[non_terminal].insert(rights.substr(start));
        }
    }
    std::cout << "\033[32m" << "文法读取成功" << "\033[0m" << std::endl;
    file.close();
}

void Grammar::printGrammar()
{
    for (const auto &production : grammar)
    {
        for (const auto &right : production.second)
        {
            std::cout << "\033[34m" << production.first << "\033[0m" << " -> " << "\033[34m" << right << "\033[0m" << std::endl;
        }
    }
}

void Grammar::elr()
{
    std::unordered_set<std::string> non_terminals;

    for (const auto &[non_terminal, _] : grammar)
    {
        non_terminals.insert(non_terminal);
    }

    for (auto it1 = non_terminals.begin(); it1 != non_terminals.end(); it1++)
    {
        for (auto it2 = non_terminals.begin(); it2 != it1; it2++)
        {
            std::unordered_set<std::string> new_rights;
            for (const auto &right1 : grammar[*it1])
            {
                if (right1.substr(0, it2->size()) == *it2)
                {
                    for (const auto &right2 : grammar[*it2])
                    {
                        new_rights.insert(right2 + right1.substr(it2->size()));
                    }
                }
                else
                {
                    new_rights.insert(right1);
                }
            }
            grammar[*it1] = new_rights;
        }
        elrDirect(*it1);
    }
}

void Grammar::elrDirect(const std::string &non_terminal)
{
    std::unordered_set<std::string> alpha; // 存储直接左递归的部分
    std::unordered_set<std::string> beta;  // 存储非左递归的部分

    for (const auto &right : grammar[non_terminal])
    {
        // 如果产生式右部以non_terminal开头，则为直接左递归
        if (right.substr(0, non_terminal.size()) == non_terminal)
        {
            alpha.insert(right.substr(non_terminal.size())); // 提取左递归后部分
        }
        else
        {
            beta.insert(right);
        }
    }

    if (!alpha.empty())
    {
        std::string new_non_terminal = non_terminal + "'"; // A'
        grammar[non_terminal].clear();
        for (const auto &b : beta)
        {
            grammar[non_terminal].insert(b + new_non_terminal); // A -> βA'
        }
        for (const auto &a : alpha)
        {
            grammar[new_non_terminal].insert(a + new_non_terminal); // A' -> αA'
        }
        grammar[new_non_terminal].insert("ε"); // A' -> ε
    }
}