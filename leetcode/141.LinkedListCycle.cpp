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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        auto speadyHead = head;

        while (head && head->next && speadyHead->next && speadyHead->next->next)
        {
            head = head->next;
            speadyHead = speadyHead->next->next;

            if (head == speadyHead)
                return true;
        }

        return false;
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