#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

// fill_n(&a[0][0], ntc * ntc, -100);

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int lo = 0, hi = lists.size() - 1;
        ListNode *root = nullptr, *curr;

        if (lo <= hi)
        {
            auto mergedList = merge(lo, hi, lists);

            for (auto val : mergedList)
            {
                if (root == nullptr)
                {
                    root = new ListNode(val);
                    curr = root;
                    continue;
                }

                curr->next = new ListNode(val);
                curr = curr->next;
            }
        }
        return root;
    }

    vector<int> merge(int lo, int hi, vector<ListNode *> &lists)
    {
        vector<int> mergedList;

        if (lo == hi)
        {
            auto first = lists[lo];
            while (first != nullptr)
            {
                mergedList.push_back(first->val);
                first = first->next;
            }

            return mergedList;
        }

        int mid = (lo + hi) >> 1;
        auto firstHalf = merge(lo, mid, lists);
        auto secondHalf = merge(mid + 1, hi, lists);

        int i = 0, j = 0;
        int l1 = firstHalf.size();
        int l2 = secondHalf.size();
        int totalSz = l1 + l2;

        for (int k = 0; k < totalSz; k++)
        {
            int v;
            if (i >= l1)
                v = secondHalf[j++];
            else if (j >= l2)
                v = firstHalf[i++];
            else if (firstHalf[i] < secondHalf[j])
                v = firstHalf[i++];
            else
                v = secondHalf[j++];
            mergedList.push_back(v);
        }

        return mergedList;
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