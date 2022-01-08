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
    void reorderList(ListNode *head)
    {
        auto crawler = head;
        stack<ListNode *> st;

        while (crawler)
        {
            st.push(crawler);
            crawler = crawler->next;
        }

        crawler = head;
        int halfCnt = (st.size() + 1) >> 1;
        int i = 0;

        while (i < halfCnt)
        {

            auto temp = st.top();
            st.pop();

            temp->next = crawler->next;
            crawler->next = temp;

            crawler = temp->next;
            i++;
        }

        crawler->next = nullptr;
    }
};