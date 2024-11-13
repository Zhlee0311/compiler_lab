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
     * @attention 判断规则：小写字母即为终结符，仅考虑单个字符
     */
    static std::unordered_set<std::string> terminal;

    /**
     * @brief 所有可以直接产生ε的的非终结符
     */
    static std::unordered_set<std::string> epsilons;

    /**
     * @brief 所有的文法产生式
     */
    static std::unordered_map<std::string, std::unordered_set<std::string>> grammar;

    /**
     * @brief 所有符号的first集
     */
    static std::unordered_map<std::string, std::unordered_set<std::string>> firstSets;

    /**
     * @brief 所有非终结符号的follow集
     */
    static std::unordered_map<std::string, std::unordered_set<std::string>> followSets;

    /**
     * @brief  ε，空串
     * @attention 不属于nterminal和terminal
     */
    const static std::string epsilon;

    /**
     * @brief 起始符号
     */
    static std::string start;

private:
    static void elrDirect(const std::string &non_terminal);
    static void updateNterminal();
    static void updateTerminal();
    static void updateEpsilons();

private:
    static void firstInit();
    static void followInit();

public:
    static std::unordered_set<std::string> firstGet(std::string GramStr);
    static std::unordered_set<std::string> followGet(std::string Nterminal);

public:
    static void clearGrammar();
    static void readGrammar();
    static void printGrammar();
    static bool empty();
    static std::unordered_map<std::string, std::unordered_set<std::string>> getGrammar();
    static void elr();
    static void exlp();
};

#endif