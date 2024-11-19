#include "dfa.hpp"
#include "mdfa.hpp"
#include "share.hpp"
#include "state_dfa.hpp"
#include "state_mdfa.hpp"
#include <deque>
#include <algorithm>

MDFA::MDFA(StateMDFA *param1, std::set<StateMDFA *> param2)
{
    initialState = param1;
    acceptStates = param2;
}

MDFA::~MDFA()
{
    acceptStates.clear();
}

MDFA *MDFA::build(DFA *dfa)
{
    StateDFA *dfa_init = dfa->getInitialState();            // 此dfa的初态
    std::set<StateDFA *> dfa_accs = dfa->getAcceptStates(); // 此dfa的终态

    std::set<StateDFA *> setAcc;  // 初始的接受状态的集合
    std::set<StateDFA *> setNAcc; // 初始的非接受状态的集合

    std::map<int, StateDFA *> statesDFA = StateDFA::getStates(); // 所有的dfa状态（dfa状态已确定，可以直接使用拷贝）
    // auto statesMDFA = StateMDFA::getStates(); // 所有的mdfa状态

    for (const auto &[id, state] : statesDFA)
    {
        if (dfa_accs.count(state))
        {
            setAcc.insert(state);
        }
        else
        {
            setNAcc.insert(state);
        }
    }

    std::deque<std::set<StateDFA *>> allSet;
    if (!setAcc.empty())
    {
        allSet.push_back(setAcc);
    }
    if (!setNAcc.empty())
    {
        allSet.push_back(setNAcc);
    }

    auto search = [](StateDFA *dfa_state, char ch) -> int
    {
        auto edges = dfa_state->getEdges();
        for (const auto &edge : edges)
        {
            if (edge.first == ch)
            {
                return edge.second; // 找到了目标状态的Id
            }
        }
        return -1; // 没找到则返回-1
    }; // 寻找一个dfa状态在某个符号条件下的转移状态Id，若无对应的转移状态则返回-1

    auto check = [&allSet, &statesDFA](int Id_1, int Id_2) -> bool
    {
        auto statesMDFA = StateMDFA::getStates(); // 在检查前需要获取MDFA的所有状态，以免丢失上一次更新

        if ((Id_1 >= 0 && Id_2 < 0) || (Id_1 < 0 && Id_2 >= 0))
        {
            return false;
        } // Id为负 和 Id非负 不属于同一个集合
        else if (Id_1 < 0 && Id_2 < 0)
        {
            return true;
        } // Id均为负代表均不存在，可以认为 “属于同一个集合”

        auto st_1 = statesDFA[Id_1];
        auto st_2 = statesDFA[Id_2];
        for (const auto &curSet : allSet)
        {
            if (curSet.count(st_1) && curSet.count(st_2))
            {
                return true;
            }
        } // 首先遍历当前未处理完的dfa状态的集合，检查其中是否存在两个Id代表的dfa状态
        for (const auto &state : statesMDFA)
        {
            auto ent = state.second->getEntity();
            if (ent.count(st_1) && ent.count(st_2))
            {
                return true;
            }
        } // 其次遍历所有mdfa的状态，其中的实体ent即为一个dfa状态的集合，检查过程与上类似
        return false;
    }; // 判断两个 dfa_state 是否属于同一个集合（若Id为-1则代表不存在此状态）

    std::unordered_map<char, int> firstTarget; // 当前处理的集合中，第一个状态面对不同符号的转换情况
    std::set<StateDFA *> trashSet;             // 当前处理的集合中，与第一个状态不属于同类的状态需要被移出并插入队尾，进行下一轮处理

    while (!allSet.empty())
    {
        firstTarget.clear();
        trashSet.clear();

        std::set<StateDFA *> &curSet = allSet.front(); // 当前处理的集合
        StateDFA *firstState = *curSet.begin();        // 当前处理的集合的第一个状态

        for (const auto &ch : Share::alphabet)
        {
            int target = search(firstState, ch); // 当前处理的集合的第一个状态在面对 "ch" 时转移到的状态的Id
            firstTarget[ch] = target;            // 不管结果如何都插入，-1也插入，代表没有对应的转换状态
        } // 构建：当前处理的集合中，第一个状态面对不同符号的转换情况

        for (auto it = curSet.begin(); it != curSet.end();)
        {
            bool moved = false;
            for (const auto &ch : Share::alphabet)
            {
                auto target = search(*it, ch);
                auto real = firstTarget[ch];
                if (!check(target, real))
                {
                    trashSet.insert(*it);
                    it = curSet.erase(it);
                    moved = true;
                    break;
                }
            }
            if (!moved)
            {
                ++it;
            }
        } // 继续处理当前的集合的剩余状态

        new StateMDFA(curSet);
        allSet.pop_front();

        if (!trashSet.empty())
        {
            allSet.push_back(trashSet);
        }
    }

    StateMDFA *param1 = nullptr;
    std::set<StateMDFA *> param2;

    for (auto &mdfa_state_1 : StateMDFA::getStates())
    {
        auto curState = mdfa_state_1.second; // 当前的MDFA状态
        auto curEnt = curState->getEntity(); // 当前MDFA状态的实体（一个DFA状态的集合）
        auto curIndiv = *curEnt.begin();     // 当前MDFA状态的实体的第一个元素（因为实体里的状态是等价状态，因此可以用这个状态代表整个实体）

        for (const auto &ch : Share::alphabet)
        {
            auto target = search(curIndiv, ch);
            if (target == -1)
                continue;
            for (auto &mdfa_state_2 : StateMDFA::getStates())
            {
                auto tgtState = mdfa_state_2.second; // 目标状态可能存在的MDFA状态
                auto tgtEnt = tgtState->getEntity(); // 目标状态可能存在的MDFA状态的实体（一个DFA状态的集合）
                if (tgtEnt.count(statesDFA[target]))
                {
                    curState->link(ch, tgtState);
                    break;
                }
            }
        }

        if (curEnt.count(dfa_init))
        {
            param1 = curState;
        }
        if (std::any_of(curEnt.begin(), curEnt.end(), [&](StateDFA *indiv)
                        { return dfa_accs.count(indiv); }))
        {
            param2.insert(curState);
        }
    }

    auto result = new MDFA(param1, param2);

    return result;
}

StateMDFA *MDFA::getInitialState()
{
    return initialState;
}

std::set<StateMDFA *> MDFA::getAcceptStates()
{
    return acceptStates;
}