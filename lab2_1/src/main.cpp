#include "nfa.hpp"
#include "state_nfa.hpp"

int StateNFA::nextId = 0;                // 初始Id为0
std::map<int, StateNFA *> StateNFA::states; // 所有Id与State的映射

int main()
{
    std::string input;
    std::cout << "请输入正规表达式：" << std::endl;
    while (std::cin >> input)
    {
        NFA *nfa = NFA::build(input);
        auto states = StateNFA::getStates();

        for (auto state : states)
        {
            auto edges = state.second->getEdges();

            std::cout << "\033[35m" << state.first << ':' << "\033[0m" << std::endl;
            for (auto edge : edges)
            {
                std::cout << state.first << "+" << edge.first << "->" << edge.second << std::endl;
            }
        }

        delete nfa;
        StateNFA::clearStates();
        std::cout << "请输入正规表达式：" << std::endl;
    }
    return 0;
}