#include "trie.hpp"
#include <queue>

Trie::Trie(std::unordered_set<std::string> words)
{
    root = new node('\0');
    for (auto it = words.begin(); it != words.end(); it++)
    {
        insert(*it);
    }
}

Trie::~Trie()
{
    std::queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *cur = q.front();
        q.pop();
        for (auto it = (cur->children).begin(); it != (cur->children).end(); it++)
        {
            q.push(it->second);
        }
        delete cur;
    }
}

void Trie::insert(std::string word)
{
    node *cur = root;
    for (const auto &c : word)
    {
        if (cur->children.find(c) == cur->children.end())
        {
            cur->children[c] = new node(c);
        }
        cur = cur->children[c];
    }
    cur->isEnd = true; // 代表这里是一个结尾
}

std::unordered_map<std::string, std::unordered_set<std::string>> Trie::getPublicPrefixes()
{
    std::unordered_map<std::string, std::unordered_set<std::string>> res; // [abc, abd, bce, bcf] => [{ab -> [c, d]}, {bc -> [e, f]}]
    std::queue<std::pair<node *, std::string>> q; // 用于广度优先搜索，第一个元素是当前节点，第二个元素是当前节点的前缀
    q.push({root, ""});
    while (!q.empty())
    {
        node *cur = q.front().first;
        std::string prefix = q.front().second;
        q.pop();
        if (cur != root && (cur->children.size() > 1 || (cur->children.size() == 1 && cur->isEnd)))
        {   
            dfs(res[prefix], cur, ""); // dfs用于查找公共前缀所有的后缀
            continue;
        }
        for (auto it = (cur->children).begin(); it != (cur->children).end(); it++)
        {
            q.push({it->second, prefix + (it->first)});
        }
    }
    return res;
}

void Trie::dfs(std::unordered_set<std::string> &res, node *now, std::string pre)
{
    if (now->isEnd)
    {
        if (pre.empty())
        {
            res.insert("ε");
        }
        else
        {
            res.insert(pre);
        }
        if (now->children.empty())
        {
            return;
        }
    }

    for (auto it = (now->children).begin(); it != (now->children).end(); it++)
    {
        dfs(res, it->second, pre + (it->first));
    }
}