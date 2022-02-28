#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        doInorderTraversal(root);

        return ans;
    }

    void doInorderTraversal(TreeNode* root){
        if(root==nullptr)
            return;

        doInorderTraversal(root->left);

        ans.push_back(root->val);

        doInorderTraversal(root->right);
    }
};