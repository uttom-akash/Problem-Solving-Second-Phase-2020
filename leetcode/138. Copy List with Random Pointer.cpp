#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        auto originalNode = head;

        // pushing copied node after original node in list
        while (originalNode)
        {
            auto copiedNode = new Node(originalNode->val);
            auto nextOriginal = originalNode->next;

            originalNode->next = copiedNode;
            copiedNode->next = nextOriginal;

            originalNode = nextOriginal;
        }

        auto copiedHead = head->next;
        originalNode = head;

        // copying random node pointer from original to copied node
        while (originalNode)
        {

            if (originalNode->random)
            {
                auto copiedNode = originalNode->next;
                auto originalRandom = originalNode->random;
                copiedNode->random = originalRandom->next;
            }
            originalNode = originalNode->next->next;
        }

        // segregating two list
        originalNode = head;
        while (originalNode)
        {
            auto nextOriginal = originalNode->next->next;
            auto copiedNode = originalNode->next;

            if (nextOriginal)
                copiedNode->next = nextOriginal->next;

            originalNode->next = nextOriginal;

            originalNode = nextOriginal;
        }

        return copiedHead;
    }
};
