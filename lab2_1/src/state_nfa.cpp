#include "state_nfa.hpp"

std::map<int, StateNFA *> StateNFA::getStates()
{
    return states;
}

void StateNFA::clearStates()
{
    for (auto state : states)
    {
        delete (state.second);
    }
    states.clear();
    nextId = 0;
}

StateNFA::StateNFA()
{
    Id = nextId;
    nextId++;
    states.emplace(Id, this);
}

StateNFA::~StateNFA()
{
    edges.clear();
}

void StateNFA::link(char condition, StateNFA *target)
{
    edges.push_back(std::pair<char, int>(condition, target->Id));
}

int StateNFA::getId()
{
    return Id;
}

std::vector<std::pair<char, int>> StateNFA::getEdges()
{
    return edges;
}