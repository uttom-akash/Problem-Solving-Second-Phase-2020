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
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root,root);
    }

    bool isMirror(TreeNode *lnode, TreeNode *rnode)
    {
        if (lnode == nullptr and rnode == nullptr)
            return true;

        if (lnode == nullptr || rnode == nullptr)
            return false;

        return lnode->val == rnode->val and isMirror(lnode->left, rnode->right) and isMirror(lnode->right, rnode->left);
    }
};