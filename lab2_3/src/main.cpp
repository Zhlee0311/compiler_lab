#include "nfa.hpp"
#include "dfa.hpp"
#include "mdfa.hpp"
#include "share.hpp"
#include "state_nfa.hpp"
#include "state_dfa.hpp"
#include "state_mdfa.hpp"

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

int StateMDFA::nextId = 0;
std::map<int, StateMDFA *> StateMDFA::states;

int main()
{
    while (true)
    {
        std::cout << "请输入正规表达式:" << std::endl;
        std::string input;
        std::cin >> input;

        auto nfa = NFA::build(input); // 构建NFA
        auto dfa = DFA::build(nfa);   // 构建DFA
        auto mdfa = MDFA::build(dfa); // 构建最小DFA

        StateNFA::showStates(nfa); // 展示
        StateDFA::showStates(dfa);
        StateMDFA::showStates(mdfa);

        delete nfa;  // 释放nfa内存
        delete dfa;  // 释放dfa内存
        delete mdfa; // 释放mdfa内存

        StateMDFA::clearStates(); // 释放StateMDFA内存
        StateDFA::clearStates();  // 释放StateNFA内存
        StateNFA::clearStates();  // 释放StateNFA内存

        char choice;
        std::cout << "是否继续处理另一个正规表达式？(y/n): ";
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
    }
    return 0;
}