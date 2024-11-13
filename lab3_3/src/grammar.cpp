#include "grammar.hpp"
#include "trie.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cctype>
#include <queue>

namespace fs = std::filesystem;

/**
 * @brief 更新该文法中的非终结符
 */
void Grammar::updateNterminal()
{
    nterminal.clear();
    for (const auto &[left, rights] : grammar)
    {
        nterminal.insert(left);
        for (const auto &right : rights)
        {
            for (const auto &ch : right)
            {
                if (right == epsilon)
                {
                    continue; // 忽略空串
                }
                if (isupper(ch))
                {
                    nterminal.insert(std::string(1, ch));
                }
            }
        }
    }
}

/**
 * @brief 更新该文法中的终结符
 */
void Grammar::updateTerminal()
{
    terminal.clear();
    for (const auto &[left, rights] : grammar)
    {
        for (const auto &right : rights)
        {
            if (right == epsilon)
            {
                continue; // 忽略空串
            }
            for (const auto &ch : right)
            {
                if (!isupper(ch))
                {
                    terminal.insert(std::string(1, ch));
                }
            }
        }
    }
}

/**
 * @brief 更新该文法中产生Epsilon的非终结符
 */
void Grammar::updateEpsilons()
{
    epsilons.clear();
    for (const auto &[left, rights] : grammar)
    {
        if (rights.count(epsilon))
        {
            epsilons.insert(left);
        }
    }
}

void Grammar::clearGrammar()
{
    nterminal.clear();
    terminal.clear();
    epsilons.clear();
    grammar.clear();
    firstSets.clear();
    followSets.clear();
    start.clear();
}

void Grammar::readGrammar()
{
    std::string filename;
    std::cout << "\033[33m" << "请输入1个文法文件的名称: " << "\033[0m" << std::endl;
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
    bool startSet = false;
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
            if (!startSet)
            {
                Grammar::start = non_terminal; //  设定起始符号
                startSet = true;
            }
        }
    }

    updateNterminal();
    updateTerminal();
    updateEpsilons();

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

std::unordered_map<std::string, std::unordered_set<std::string>> Grammar::getGrammar()
{
    return grammar;
}

/**
 * @brief 利用trie树提取左公因子（会修改文法）
 */
void Grammar::exlp()
{
    for (auto it = grammar.begin(); it != grammar.end(); it++)
    {
        auto &rights = it->second; // ex. ab | abc | abd | da | dc | e

        Trie *trie = new Trie(rights);
        auto refs = trie->getPublicPrefixes(); // ex. {ab + {c,d,ε}  d + {a,c} }
        delete trie;

        std::unordered_map<std::string, std::string> new_nonterminals; // 公共前缀后跟新的非终结符
        for (const auto &[pub, sufs] : refs)
        {
            for (int i = 0; i < 26; i++)
            {
                std::string new_nonterminal = std::string(1, 65 + i); // 待替换的新的非终结符
                // 检查这个非终结符是否使用
                if (!nterminal.count(new_nonterminal))
                {
                    new_nonterminals[pub] = new_nonterminal;
                    break;
                }
            }

            rights.insert(pub + new_nonterminals[pub]);

            for (const auto &suf : sufs)
            {
                if (suf == epsilon)
                {
                    rights.erase(pub);
                }
                else
                {
                    rights.erase(pub + suf);
                }
                grammar[new_nonterminals[pub]].insert(suf);
            }
            updateNterminal();
            updateTerminal();
            updateEpsilons();
        }
    }
}

/**
 * @brief 消除左递归（会修改文法）
 * @attention 这里的non_terminals仅包含产生式左边的非终结符号
 */
void Grammar::elr()
{
    std::unordered_set<std::string> non_terminals; // 这里的non_terminals仅包含产生式左边的非终结符号

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
    updateNterminal();
    updateTerminal();
    updateEpsilons();
}

/**
 * @brief 消除直接左递归（配合elr使用）
 */
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
        grammar[new_non_terminal].insert(epsilon); // A' -> ε
    }
}

void Grammar::firstInit()
{
    firstSets.clear();

    // 初始化终结符的 FIRST 集合
    for (const auto &t : terminal)
    {
        firstSets[t].insert(t);
    }

    bool changed;
    do
    {
        changed = false;
        for (const auto &[left, rights] : grammar)
        {
            for (const auto &right : rights)
            {
                if (right == epsilon)
                {
                    if (firstSets[left].insert(epsilon).second)
                    {
                        changed = true;
                    }
                    continue;
                }

                bool existEpsilon = true;
                size_t i = 0;
                while (i < right.size() && existEpsilon)
                {
                    existEpsilon = false;
                    std::string symbol(1, right[i]);
                    for (const auto &firstSymbol : firstSets[symbol])
                    {
                        if (firstSymbol != epsilon)
                        {
                            if (firstSets[left].insert(firstSymbol).second)
                            {
                                changed = true;
                            }
                        }
                        else
                        {
                            existEpsilon = true;
                        }
                    }
                    i++;
                }
                if (existEpsilon)
                {
                    if (firstSets[left].insert(epsilon).second)
                    {
                        changed = true;
                    }
                }
            }
        }
    } while (changed);
}

std::unordered_set<std::string> Grammar::firstGet(std::string GramStr)
{
    firstInit();
    std::unordered_set<std::string> res;
    bool changed;
    do
    {
        if (GramStr == epsilon)
        {
            res.insert(epsilon);
            break;
        }

        changed = false;
        bool epsilonInAll = true;
        size_t i = 0;
        while (i < GramStr.size() && epsilonInAll)
        {
            epsilonInAll = false;
            for (const auto &symbol : firstSets[std::string(1, GramStr[i])])
            {
                if (symbol != epsilon)
                {
                    if (res.insert(symbol).second)
                    {
                        changed = true;
                    }
                }
                else
                {
                    epsilonInAll = true;
                }
            }
            i++;
        }
        if (epsilonInAll)
        {
            if (res.insert(epsilon).second)
            {
                changed = true;
            }
        }
    } while (changed);
    return res;
}

void Grammar::followInit()
{
    followSets.clear();

    followSets[start].insert("$");

    bool changed;
    do
    {
        changed = false;
        for (const auto &nt : nterminal)
        {
            for (const auto &[left, rights] : grammar)
            {
                for (const auto &right : rights)
                {
                    size_t pos = right.find(nt);
                    if (pos == std::string::npos)
                    {
                        continue;
                    }
                    else if (pos == right.size() - 1)
                    {
                        auto frontAppend = followSets[left];
                        for (const auto &symbol : frontAppend)
                        {
                            if (followSets[nt].insert(symbol).second)
                            {
                                changed = true;
                            }
                        }
                    }
                    else
                    {
                        auto backAppend = firstGet(right.substr(pos + 1));
                        if (backAppend.count(epsilon))
                        {
                            auto frontAppend = followSets[left];
                            for (const auto &symbol : frontAppend)
                            {
                                if (followSets[nt].insert(symbol).second)
                                {
                                    changed = true;
                                }
                            }
                        }
                        backAppend.erase(epsilon);
                        for (const auto &symbol : backAppend)
                        {
                            if (followSets[nt].insert(symbol).second)
                            {
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    } while (changed);
}

std::unordered_set<std::string> Grammar::followGet(std::string Nterminal)
{
    followInit();
    return followSets[Nterminal];
}

bool Grammar::empty()
{
    return grammar.empty();
}