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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return DnQ(nums,0,nums.size()-1);
    }

    TreeNode *DnQ(vector<int> &nums, int l, int r)
    {
        int mid = (l + r) >> 1;

        TreeNode *root = new TreeNode(nums[mid]);

        if (l <= mid - 1)
            root->left = DnQ(nums, l, mid - 1);

        if (mid + 1 <= r)
            root->right = DnQ(nums, mid + 1, r);

        return root;
    }
};