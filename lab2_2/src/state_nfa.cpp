#include "state_nfa.hpp"
#include <queue>
#include <iostream>

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
    edges.push_back(std::pair<char, int>(condition, target->getId()));
}

std::set<StateNFA *> StateNFA::epsilonClosure()
{
    std::set<StateNFA *> res;       // 最终返回的结果
    std::queue<StateNFA *> toCheck; // 待检查是否有epsilon边的状态队列， a + epsilon -> b ，则b属于a的epsilon_closure

    res.insert(this);
    toCheck.push(this);

    while (!toCheck.empty())
    {
        StateNFA *cur = toCheck.front();
        toCheck.pop();
        for (const auto &edge : cur->edges)
        {
            if (edge.first == '#')
            {
                StateNFA *nex = states[edge.second];
                if (res.find(nex) == res.end())
                {
                    res.insert(nex);
                    toCheck.push(nex);
                }
            }
        }
    }
    return res;
}

std::set<StateNFA *> StateNFA::charClosure(char a)
{
    std::set<StateNFA *> res;
    std::queue<StateNFA *> toCheck;

    toCheck.push(this);
    while (!toCheck.empty())
    {
        StateNFA *cur = toCheck.front();
        toCheck.pop();
        for (const auto &edge : cur->edges)
        {
            if (edge.first == a)
            {
                StateNFA *nex = states[edge.second];
                if (res.find(nex) == res.end())
                {
                    res.insert(nex);
                    toCheck.push(nex);
                }
            }
        }
    }
    return res;
}

int StateNFA::getId()
{
    return Id;
}

std::vector<std::pair<char, int>> StateNFA::getEdges()
{
    return edges;
}

void StateNFA::showStates()
{
    std::cout << "\033[32m" << "以下为NFA:" << "\033[0m" << std::endl;
    for (const auto &state : states)
    {
        const auto &edges = state.second->getEdges();
        std::cout << "\033[35m" << "State" << state.first << ":" << "\033[0m" << std::endl;
        for (const auto &edge : edges)
        {
            std::cout << " + " << edge.first << " ---> " << "\033[35m" << "State" << edge.second << "\033[0m" << std::endl;
        }
    }
}