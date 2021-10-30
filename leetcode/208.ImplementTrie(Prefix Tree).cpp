#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *pCrawl = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
            {
                pCrawl->children[index] = new TrieNode();
            }
            pCrawl = pCrawl->children[index];
        }

        pCrawl->isEndOfWord = true;
    }

    bool search(string word)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return (pCrawl->isEndOfWord);
    }

    bool startsWith(string prefix)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */