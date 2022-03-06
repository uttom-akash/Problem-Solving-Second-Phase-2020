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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        return doTraverse(root);
    }

    vector<vector<int>> doTraverse(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool fromleft = true;
        vector<vector<int>> ans;

        while (!q.empty())
        {
            auto sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; i++)
            {
                auto parent = q.front();
                q.pop();

                if (parent == nullptr)
                    continue;

                level.push_back(parent->val);

                q.push(parent->left);
                q.push(parent->right);
            }

            if (fromleft == false)
                reverse(level.begin(), level.end());

            ans.push_back(level);

            fromleft = !fromleft;
        }

        return ans;
    }
};

