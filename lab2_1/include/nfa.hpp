#ifndef __NFA_HPP
#define __NFA_HPP

#include <iostream>
#include <set>

class State;

class NFA
{
private:
    std::set<State *> initialStates;
    std::set<State *> acceptStates;

public:
    NFA(char character);
    NFA(State *initial, State *accept);
    NFA(std::set<State *> initialStates, std::set<State *> acceptStates);
    ~NFA();

public:
    NFA *closure();

    NFA *concat(NFA *next);

    NFA *select(NFA *other);

    std::set<State *> getInitialStates();
    std::set<State *> getAcceptStates();

public:
    /**
     * @brief 根据输入的字符串构造NFA
     */
    static NFA *build(std::string input);
};

#endif