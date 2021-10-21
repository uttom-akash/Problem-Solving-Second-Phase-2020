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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int ans = 0;
        stack<pair<TreeNode *, int>> tracker;
        tracker.push({root, 1});

        while (!tracker.empty())
        {
            auto u = tracker.top();
            ans = max(ans, u.second);
            if (u.first->left != nullptr)
            {
                tracker.push({u.first->left, u.second + 1});
            }

            if (u.first->right != nullptr)
            {
                tracker.push({u.first->right, u.second + 1});
            }
        }

        return ans;
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

    int a[3];
    for (int i = 0; scanf("%d", &a[i]); i++)
    {
        cout << a[i] << '\n';
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}