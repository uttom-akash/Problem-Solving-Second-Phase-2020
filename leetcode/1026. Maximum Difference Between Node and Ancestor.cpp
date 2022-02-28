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
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;

        traverse(root,&ans);

        return ans;
    }

    pair<int,int> traverse(TreeNode* root, int* ans){
        int smallest=root->val, largest=root->val;

        if(root->left){
            auto l = traverse(root->left,ans);
            smallest = min(smallest,l.first);
            largest = max(largest,l.second);
        }

        if(root->right){
            auto r = traverse(root->right,ans);
            smallest = min(smallest,r.first);
            largest = max(largest,r.second);
        }
        
        *ans = max(*ans,max(abs(root->val-smallest),abs(root->val-largest)));
        
        return {smallest,largest};
    }
};