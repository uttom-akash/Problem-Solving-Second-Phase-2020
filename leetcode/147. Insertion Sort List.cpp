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
    ListNode *insertionSortList(ListNode *head)
    {
        int cnt = 0;
        auto crawler = head;

        while (crawler != nullptr)
        {
            crawler = crawler->next;
            cnt++;
        }

        int i = 0;
        while (--cnt)
        {
            auto place = head;
            int j = 0;
            while (place != nullptr && j < i)
            {
                place = place->next;
                j++;
            }

            crawler = place;
            while (crawler != nullptr)
            {
                if (place->val > crawler->val)
                {
                    swap(place->val, crawler->val);
                }
                crawler = crawler->next;
            }

            i++;
        }

        return head;
    }
};