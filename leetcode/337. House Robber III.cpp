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
    int rob(TreeNode *root)
    {
        auto ans = traverse(root);
        return max(ans.first, ans.second);
    }

    pair<int, int> traverse(TreeNode *root)
    {

        pair<int, int> leftPair = {0, 0};
        pair<int, int> rightPair = {0, 0};

        if (root->left)
        {
            leftPair = traverse(root->left);
        }

        if (root->right)
        {
            rightPair = traverse(root->right);
        }

        int takeIt = root->val + leftPair.second + rightPair.second;
        int ignoreIt = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);

        return {takeIt, ignoreIt};
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