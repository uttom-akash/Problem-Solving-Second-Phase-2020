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
    ListNode *sortList(ListNode *head)
    {
        return margeSort(head);
    }

    ListNode *margeSort(ListNode *head)
    {
        if (head->next == nullptr)
            return head;

        auto mid = middleNode(head);
        auto left = margeSort(head);
        auto right = margeSort(mid);

        ListNode *temp = new ListNode();
        auto ptr = temp;

        while (left && right)
        {
            if (left->val < right->val)
                ptr->next = left, left = left->next;
            else
                ptr->next = right, right = right->next;

            ptr = ptr->next;
        }

        if (left)
            ptr->next = left;
        else
            ptr->next = right;

        return temp->next;
    }

    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        return slow;
    }
};