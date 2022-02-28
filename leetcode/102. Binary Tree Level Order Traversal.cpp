#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        return doBFS(root);
    }

    vector<vector<int>> doBFS(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; i++)
            {
                auto u = q.front();
                q.pop();

                level.push_back(u->val);

                if (u->left)
                    q.push(u->left);

                if (u->right)
                    q.push(u->right);
            }

            ans.push_back(level);
        }
    }
};
