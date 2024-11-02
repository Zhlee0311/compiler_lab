#include "state.hpp"
#include "nfa.hpp"
#include <stack>
#include <unordered_map>

std::string trans_postfix(std::string s);
std::string pre_process(std::string s);
extern std::unordered_map<char, int> precedence;

NFA::NFA(char character)
{

    State *initial = new State();
    State *accept = new State();
    initial->link(character, accept);

    initialStates.insert(initial);
    acceptStates.insert(accept);
}

NFA::NFA(State *initial, State *accept)
{
    initialStates.insert(initial);
    acceptStates.insert(accept);
}

NFA::NFA(std::set<State *> initialStates, std::set<State *> acceptStates)
{
    this->initialStates = initialStates;
    this->acceptStates = acceptStates;
}

NFA::~NFA()
{
    initialStates.clear();
    acceptStates.clear();
}

NFA *NFA::closure()
{
    State *initial_new = new State();
    State *accept_new = new State();

    initial_new->link('#', accept_new);

    for (State *initial : initialStates)
    {
        initial_new->link('#', initial);
    }

    for (State *accept : acceptStates)
    {
        accept->link('#', accept_new);
    }

    for (State *accept : acceptStates)
    {
        for (State *initial : initialStates)
        {
            accept->link('#', initial);
        }
    }
    auto res = new NFA(initial_new, accept_new);
    return res;
}

NFA *NFA::concat(NFA *next)
{
    for (State *rear : acceptStates)
    {
        for (State *front : next->initialStates)
        {
            rear->link('#', front);
        }
    }
    auto res = new NFA(initialStates, next->acceptStates);
    return res;
}

NFA *NFA::select(NFA *other)
{
    State *initial_new = new State();
    State *accept_new = new State();

    for (State *initial : initialStates)
    {
        initial_new->link('#', initial);
    }

    for (State *initial : other->initialStates)
    {
        initial_new->link('#', initial);
    }
    for (State *accept : acceptStates)
    {
        accept->link('#', accept_new);
    }
    for (State *accept : other->acceptStates)
    {
        accept->link('#', accept_new);
    }
    auto res = new NFA(initial_new, accept_new);
    return res;
}

std::set<State *> NFA::getInitialStates()
{
    return initialStates;
}

std::set<State *> NFA::getAcceptStates()
{
    return acceptStates;
}

NFA *NFA::build(std::string input)
{
    input = trans_postfix(pre_process(input)); // 对输入进行预处理
    std::stack<NFA *> tmps;                    // 用于存储NFA中间运算结果的栈

    for (char ch : input)
    {
        if (precedence.find(ch) == precedence.end())
        {
            NFA *tmp = new NFA(ch);
            tmps.push(tmp);
        }
        else if (ch == '*')
        {
            NFA *tmp = tmps.top()->closure();
            delete tmps.top();
            tmps.pop();
            tmps.push(tmp);
        }
        else if (ch == '@')
        {
            NFA *tmp1 = tmps.top();
            tmps.pop();
            NFA *tmp2 = tmps.top();
            tmps.pop();
            NFA *tmp = tmp2->concat(tmp1);
            delete tmp1;
            delete tmp2;
            tmps.push(tmp);
        }
        else if (ch == '|')
        {
            NFA *tmp1 = tmps.top();
            tmps.pop();
            NFA *tmp2 = tmps.top();
            tmps.pop();
            NFA *tmp = tmp2->select(tmp1);
            delete tmp1;
            delete tmp2;
            tmps.push(tmp);
        }
    }
    return tmps.top();
}