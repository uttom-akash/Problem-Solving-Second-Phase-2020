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
private:
    int ans = INT_MIN;

public:
    int dfs(TreeNode *u)
    {
        int lscore = u->val, rscore = u->val;
        if (u->left != nullptr)
            lscore += dfs(u->left);

        if (u->right != nullptr)
            rscore += dfs(u->right);

        ans = max(ans, u->val);
        ans = max(ans, lscore + rscore - u->val);
        ans = max(ans, lscore);
        ans = max(ans, rscore);

        return max(u->val, max(lscore, rscore));
    }

    int maxPathSum(TreeNode *root)
    {
        dfs(root);
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