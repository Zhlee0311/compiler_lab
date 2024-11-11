#ifndef __GRAMMAR_HPP
#define __GRAMMAR_HPP

#include <unordered_map>
#include <unordered_set>
#include <string>

class Grammar
{
private:
    /**
     * @brief 所有的非终结符，无论是否在产生式左边出现过
     * @attention 判断规则：大写字母即为非终结符
     */
    static std::unordered_set<std::string> nterminal;

    /**
     * @brief 所有的终结符
     */
    static std::unordered_set<std::string> terminal;

    /**
     * @brief 所有的文法产生式
     */
    static std::unordered_map<std::string, std::unordered_set<std::string>> grammar;

    /**
     * @brief  ε，空串
     * @attention 不属于nterminal和terminal
     */
    const static std::string epsilon;

private:
    static void elrDirect(const std::string &non_terminal);
    static void updateNterminal();

public:
    static void clearGrammar();
    static void readGrammar();
    static void printGrammar();
    static std::unordered_map<std::string, std::unordered_set<std::string>> getGrammar();
    static void elr();
    static void exlp();
};


#endif