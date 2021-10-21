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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
    }

    bool checkIsSimilar(TreeNode *root, TreeNode *subRoot)
    {
        stack<pair<TreeNode *, TreeNode *>> tracker;
        tracker.push({root, subRoot});

        while (!tracker.empty())
        {
            auto both = tracker.top();
            tracker.pop();

            if (both.first == nullptr && both.second == nullptr)
                continue;

            if (both.first == nullptr || both.second == nullptr)
                return false;

            if (both.first->val != both.second->val)
                return false;

            tracker.push({both.first->left, both.second->left});
            tracker.push({both.first->right, both.second->right});
        }

        return true;
    }

    pair<bool, int> traverse(TreeNode *root, TreeNode *subRoot, int subHeight)
    {
        int revHeight = 0;

        if (root == nullptr)
        {
            auto result = checkIsSimilar(root, subRoot);
            return {result, 0};
        }

        auto res = traverse(root->left, subRoot, subHeight);
        revHeight = max(revHeight, res.second);

        if (res.first)
        {
            return {true, 0};
        }

        res = traverse(root->right, subRoot, subHeight);
        revHeight = max(revHeight, res.second);

        if (res.first)
        {
            return {true, 0};
        }

        if (revHeight == subHeight)
        {
        }

        return {false, revHeight};
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