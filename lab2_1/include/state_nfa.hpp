#ifndef __STATE_NFA_HPP
#define __STATE_NFA_HPP

#include <vector>
#include <map>

/**
 * @brief StateNFA 记录状态之间的连接关系
 */
class StateNFA
{
private:
    int Id;                                  // 唯一标识这个状态的Id
    std::vector<std::pair<char, int>> edges; // 状态与其他状态之间的边

private:
    static int nextId;
    static std::map<int, StateNFA *> states;

public:
    static std::map<int, StateNFA *> getStates();
    static void clearStates();

public:
    StateNFA();

    ~StateNFA();

    void link(char condition, StateNFA *target);

    int getId();

    std::vector<std::pair<char, int>> getEdges();
};

#endif