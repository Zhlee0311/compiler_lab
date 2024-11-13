#ifndef __TRIE_HPP
#define __TRIE_HPP

#include <unordered_map>
#include <unordered_set>
#include <string>

struct node
{
    char data;
    std::unordered_map<char, node *> children;
    bool isEnd;

    node(char c)
    {
        data = c;
        isEnd = false;
    }
};

class Trie
{
public:
    Trie(std::unordered_set<std::string> words);
    ~Trie();

public:
    std::unordered_map<std::string, std::unordered_set<std::string>> getPublicPrefixes();

private:
    node *root;

private:
    void insert(std::string word);
    void dfs(std::unordered_set<std::string> &res, node *now, std::string pre);
};

#endif