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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        stack<pair<TreeNode *, pair<ll, ll>>> keepNote;
        keepNote.push({root, {INT_MIN - 10LL, INT_MAX + 10LL}});

        while (!keepNote.empty())
        {
            auto info = keepNote.top();
            auto u = info.first;
            auto lo = info.second.first;
            auto hi = info.second.second;

            keepNote.pop();

            if (u->right != nullptr)
            {
                ll nlo = max((ll)u->val, lo);
                if (nlo < u->right->val && u->right->val < hi)
                    keepNote.push({u->right, {nlo, hi}});
                else
                    return false;
            }

            if (u->left != nullptr)
            {
                ll nhi = min((ll)u->val, hi);
                if (lo < u->left->val && u->left->val < nhi)
                    keepNote.push({u->left, {lo, nhi}});
                else
                    return false;
            }
        }

        return true;
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