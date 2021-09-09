#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "input.txt", string fout = "output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head)
        {
            cout << head->val << "--\n";
            auto temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }

    void print(ListNode *head)
    {
        auto curr = head;
        while (curr)
        {

            cout << curr->val << "\n";
            curr = curr->next;
        }
    }
};

void solve()
{
    vector<int> v({1, 2, 3, 4, 5});

    ListNode *head = new ListNode();
    auto curr = head;
    for (int tc = 0; tc < v.size(); tc++)
    {
        curr->next = new ListNode(v[tc]);
        curr = curr->next;
    }

    Solution s;
    s.print(head);
    head = s.reverseList(head);
    s.print(head);
}

int main()
{
    optimize();

    solve();

    return 0;
}