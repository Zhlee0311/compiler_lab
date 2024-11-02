#include "state_dfa.hpp"
#include "state_nfa.hpp"

std::map<int, StateDFA *> StateDFA::getStates()
{
    return states;
}

void StateDFA::clearStates()
{
    for (auto state : states)
    {
        delete state.second;
    }
    states.clear();
    nextId = 0;
}

StateDFA::StateDFA()
{
    Id = nextId;
    nextId++;
    states.emplace(Id, this);
}

StateDFA::~StateDFA()
{
    edges.clear();
    entity.clear(); // 里面指针指向的内存并不需要释放，由StateNFA统一管理
}

void StateDFA::link(char condition, StateDFA *target)
{
    edges.push_back(std::pair<char, int>(condition, target->getId()));
}

std::set<StateNFA *> StateDFA::epsilonClosure()
{
    std::set<StateNFA *> res;
    for (const auto &state : entity)
    {
        auto closure = state->epsilonClosure();
        res.insert(closure.begin(), closure.end());
    }
    return res;
} // 集合的epsilon_closure

std::set<StateNFA *> StateDFA::charClosure(char a)
{
    std::set<StateNFA *> res;
    for (const auto &state : entity)
    {
        auto closure = state->charClosure(a);
        res.insert(closure.begin(), closure.end());
    }
    return res;
} // 集合的char_closure

int StateDFA::getId()
{
    return Id;
}

std::vector<std::pair<char, int>> StateDFA::getEdges()
{
    return edges;
}