
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
    int sum;

public:
    int sumRootToLeaf(TreeNode *root)
    {
        sum = 0;
        traverseBT(root, 0);
        return sum;
    }

    void traverseBT(TreeNode *root, int pathSum)
    {

        pathSum = pathSum * 2 + root->val;

        bool isLeaf = true;
        if (root->left != nullptr)
        {
            traverseBT(root->left, pathSum);
            isLeaf = false;
        }

        if (root->right != nullptr)
        {
            traverseBT(root->right, pathSum);
            isLeaf = false;
        }

        if (isLeaf)
        {
            sum += pathSum;
        }
    }
};