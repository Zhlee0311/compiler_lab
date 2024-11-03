#include "nfa.hpp"
#include "dfa.hpp"
#include "share.hpp"
#include "state_nfa.hpp"
#include "state_dfa.hpp"

std::unordered_map<char, int> Share::precedence = {
    {'*', 3}, // 闭包
    {'@', 2}, // 连接
    {'|', 1}, // 或
    {'(', 0},
    {')', -1}};

std::unordered_set<char> Share::alphabet;


int StateNFA::nextId = 0;
std::map<int, StateNFA *> StateNFA::states;


int StateDFA::nextId = 0;
std::map<int, StateDFA *> StateDFA::states;


int main()
{
    std::string input;
    std::cout << "请输入正规表达式:" << std::endl;
    while (std::cin >> input)
    {
        auto nfa = NFA::build(input); // 构建NFA
        auto dfa = DFA::build(nfa); // 构建DFA

        StateNFA::showStates(nfa); // 展示
        StateDFA::showStates(dfa);

        delete nfa;  // 释放nfa内存
        delete dfa; // 释放dfa内存

        StateNFA::clearStates(); // 释放StateNFA内存
        StateDFA::clearStates(); // 释放StateNFA内存

        std::cout << "请输入正规表达式:" << std::endl;
    }
    return 0;
}