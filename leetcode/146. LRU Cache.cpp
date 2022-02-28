#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

struct Node
{
    Node *prev, *next;
    int key, val;

    Node(Node *p, Node n, int k, int v)
    {
        prev = p;
        next = n;
        key = k;
        val = v;
    }
};

class LRUCache
{
public:
    Node *head, *tail;
    int cap;
    map<int, Node *> mp;

    LRUCache(int capacity)
    {
        head = new Node(nullptr, nullptr, -1, -1);
        tail = new Node(nullptr, nullptr, -1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }

    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key)
    {
        if (mp[key] == nullptr)
            return -1;

        deleteNode(mp[key]);
        addNode(mp[key]);

        return mp[key]->val;
        ;
    }

    void put(int key, int value)
    {

        if (mp[key] != nullptr)
        {
            deleteNode(mp[key]);
            mp.erase(key);
        }

        if (mp.size() == cap)
        {
            auto lru = tail->prev;
            deleteNode(mp[key])
                mp.erase(lru->key)
        }

        mp[key] = new Node(nullptr, nullptr, key, value);
        addNode(mp[key]);
    }
};
