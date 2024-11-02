#ifndef __STATE_HPP
#define __STATE_HPP

#include <vector>
#include <map>

/**
 * @brief State 记录状态之间的连接关系
 */
class State
{
private:
    int Id;                                  // 唯一标识这个状态的Id
    std::vector<std::pair<char, int>> edges; // 状态与其他状态之间的边

private:
    static int nextId;
    static std::map<int, State *> states;

public:
    static std::map<int, State *> getStates();
    static void clearStates();

public:
    State();

    ~State();

    void link(char condition, State *target);

    int getId();

    std::vector<std::pair<char, int>> getEdges();
};

#endif