#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *eventIterator = head ? head->next : nullptr, *lastOdd = head;

        while (eventIterator && eventIterator->next)
        {

            auto oddNode = eventIterator->next;

            eventIterator->next = oddNode->next;
            oddNode->next = lastOdd->next;
            lastOdd->next = oddNode;
            lastOdd = oddNode;

            eventIterator = eventIterator->next;
        }

        return head;
    }
};