#include "grammar.hpp"
#include "trie.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <functional>

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
            if (right == epsilon)
            {
                continue; // 忽略空串
            }
            for (int i = 0; i < right.size(); i++)
            {
                if (isupper(right[i]) && right[i + 1] != '\'')
                {
                    nterminal.insert(right.substr(i, 1));
                }
                else if (isupper(right[i]) && right[i + 1] == '\'')
                {
                    nterminal.insert(right.substr(i, 2));
                    i++;
                }
            } // 大写字母即为非终结符，仅考虑单个字符或带'的非终结符
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
                if (!isupper(ch) && ch != '\'')
                {
                    terminal.insert(std::string(1, ch));
                } // 不是大写字母且不是'即为终结符，仅考虑单个字符
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

    firstSets[epsilon].insert(epsilon);

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

                    std::string symbol;

                    if (nterminal.count(right.substr(i, 2)))
                    {
                        symbol = right.substr(i, 2);
                        i++;
                    }
                    else
                    {
                        symbol = right.substr(i, 1);
                    }

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

            std::string symbol;
            if (nterminal.count(GramStr.substr(i, 1)) && GramStr[i + 1] == '\'')
            {
                symbol = GramStr.substr(i, 2);
                i++;
            }
            else
            {
                symbol = GramStr.substr(i, 1);
            }

            for (const auto &symbol : firstSets[symbol])
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
                    size_t pos = std::string::npos;
                    if (nt.size() == 2)
                    {
                        pos = right.find(nt); // T' 必须找到 T'
                    }
                    else
                    {
                        for (int i = 0; i < right.size(); i++)
                        {
                            if (right[i] == nt[0] && (i == right.size() - 1 || right[i + 1] != '\''))
                            {
                                pos = i;
                                break;
                            }
                        }
                    }

                    if (pos == std::string::npos)
                    {
                        continue;
                    }
                    else if (pos == right.size() - nt.size())
                    {
                        auto frontAppend = followSets[left];
                        for (const auto &symbol : frontAppend)
                        {
                            if (followSets[nt].insert(symbol).second)
                            {
                                changed = true;
                            }
                        }
                    } // 该非终结符在产生式右部的最后
                    else
                    {
                        auto backAppend = firstGet(right.substr(pos + nt.size()));
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

std::unordered_set<std::string> Grammar::selectGet(std::string left, std::string right)
{
    std::unordered_set<std::string> part1 = firstGet(right);
    std::unordered_set<std::string> part2 = followGet(left);

    if (part1.count(epsilon))
    {
        part1.erase(epsilon);
        part1.insert(part2.begin(), part2.end());
    }

    return part1;
}

bool Grammar::isLL1()
{
    auto check = [](std::unordered_set<std::string> a, std::unordered_set<std::string> b) -> bool
    {
        for (const auto &element : a)
        {
            if (b.count(element))
            {
                return true;
            }
        }
        return false;
    }; // 检查两个集合有无交集

    for (const auto &[left, rights] : grammar)
    {
        for (auto it_fast = rights.begin(); it_fast != rights.end(); it_fast++)
        {
            for (auto it_slow = rights.begin(); it_slow != it_fast; it_slow++)
            {
                auto select1 = selectGet(left, *it_fast);
                auto select2 = selectGet(left, *it_slow);

                if (check(select1, select2))
                {
                    return false;
                } // 若有交集，则不是LL1文法
            }
        }
    }
    return true;
}

void Grammar::parseLL1(std::string sentence)
{

    std::unordered_map<std::pair<std::string, std::string>, std::string,
                       std::function<size_t(const std::pair<std::string, std::string> &)>>
        table(
            10,
            [](const std::pair<std::string, std::string> &p) -> size_t
            {
                size_t h1 = std::hash<std::string>()(p.first);
                size_t h2 = std::hash<std::string>()(p.second);
                return h1 ^ (h2 << 1);
            });
    //<终结符，非终结符> <替换式>，终结符遇到非终结符，用替换式替换掉终结符

    for (const auto &[left, rights] : grammar)
    {
        for (const auto &right : rights)
        {
            auto select = selectGet(left, right);
            if (!select.empty())
            {
                for (const auto &s : select)
                {
                    table[{left, s}] = right;
                }
            }
        }
    }

    std::stack<std::string> tmp; // 存储分析过程的辅助栈
    tmp.push("$");
    tmp.push(start);

    sentence.append("$");
    std::string matched = ""; // 存储已匹配的字符串

    while (!tmp.empty())
    {
        std::string curTop = tmp.top();
        std::string curInput = std::string(1, *sentence.begin());
        tmp.pop();
        if (nterminal.count(curTop))
        {
            if (!table.count({curTop, curInput}))
            {
                std::cout << "\033[31m" << "Syntax Error: " << "No production for " << curTop << " when facing " << curInput << "\033[0m" << std::endl;
                return;
            }
            else
            {
                std::string replace = table[{curTop, curInput}];
                if (replace != epsilon)
                {
                    int pos = replace.size() - 1;
                    while (pos >= 0)
                    {
                        if (replace[pos] == '\'' && nterminal.count(replace.substr(pos - 1, 2)))
                        {
                            tmp.push(replace.substr(pos - 1, 2));
                            pos -= 2;
                        }
                        else
                        {
                            tmp.push(std::string(1, replace[pos]));
                            pos--;
                        }
                    }
                }
                std::cout << "\033[34m" << "Replace: " << curTop << " -> " << replace << "\033[0m" << std::endl;
            }
        } // 若当前处理的是非终结符
        else
        {
            if (curTop == curInput)
            {
                matched += curInput;
                sentence.erase(0, 1);
                std::cout << "\033[32m" << "Match: " << curInput << "\033[0m" << std::endl;
                std::cout << "\033[36m" << "Now Matched: " << matched << "\033[0m" << std::endl;
            }
            else
            {
                std::cout << "\033[31m" << "Syntax Error: " << "No matched terminal for " << curInput << "\033[0m" << std::endl;
                return;
            }
        } // 若当前处理的是终结符
    }
    std::cout << "\033[35m" << "Parsing Success: " << matched << "\033[0m" << std::endl;
}