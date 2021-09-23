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
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *curr = head, *prev = nullptr;

        while (curr != nullptr)
        {
            auto next = curr->next;

            curr->next = prev;
            prev = curr;

            curr = next;
        }

        return prev;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto lastNode = reverseLinkedList(head);
        ListNode *curr = lastNode, *prev;

        n--;
        while (n-- && curr != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        if (prev != nullptr)
        {
            prev->next = curr->next;
        }
        else
        {
            lastNode = lastNode->next;
        }

        return reverseLinkedList(lastNode);
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        string s;
        cin >> s;
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}