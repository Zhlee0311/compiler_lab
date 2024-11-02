#include "state.hpp"


std::map<int, State *> State::getStates()
{
    return states;
}

void State::clearStates()
{
    for (auto state : states)
    {
        delete (state.second);
    }
    states.clear();
    nextId = 0;
}

State::State()
{
    Id = nextId;
    nextId++;
    states.emplace(Id, this);
}

State::~State()
{
    edges.clear();
}

void State::link(char condition, State *target)
{
    edges.push_back(std::pair<char, int>(condition, target->Id));
}

int State::getId()
{
    return Id;
}

std::vector<std::pair<char, int>> State::getEdges()
{
    return edges;
}