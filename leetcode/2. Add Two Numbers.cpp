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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        reverseList(l1);
        reverseList(l2);
        int carry = 0;

        ListNode *head = new ListNode();
        ListNode *curr = head, *curr1 = l1, *curr2 = l2;

        while (curr1 || curr2)
        {
            int sum = carry;

            if (curr1)
            {
                sum += curr1->val;
                curr1=curr1->next;
            }

            if (curr2)
            {
                sum += curr2->val;
                curr2=curr2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        head=head->next;
        reverseList(head);
        return head;
    }

    void reverseList(ListNode *head)
    {

        auto curr = head;
        ListNode *prev = nullptr, *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};