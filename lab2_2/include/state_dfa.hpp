#ifndef __STATE_DFA_HPP
#define __STATE_DFA_HPP

#include <vector>
#include <map>
#include <set>

class StateNFA;

/**
 * @brief DFA的状态，即NFA的状态集合
 */
class StateDFA
{
private:
    int Id;
    std::vector<std::pair<char, int>> edges;
    std::set<StateNFA *> entity;

private:
    static int nextId;
    static std::map<int, StateDFA *> states;

public:
    static std::map<int, StateDFA *> getStates();
    static void clearStates();

public:
    StateDFA();

    ~StateDFA();

    void link(char condition, StateDFA *target);

    std::set<StateNFA *> epsilonClosure(); // 集合的epsilon_closure

    std::set<StateNFA *> charClosure(char a); // 集合的char_closure

    int getId();

    std::vector<std::pair<char, int>> getEdges();
};

#endif