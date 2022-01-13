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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        auto newNode = new TreeNode(val);
        TreeNode *crawler = root;

        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            while (true)
            {
                if (crawler->val < val)
                {
                    if(crawler->right==nullptr){
                        crawler->right=newNode;
                        break;
                    }

                    crawler = crawler->right;
                }
                else
                {
                    if(crawler->left==nullptr){
                        crawler->left=newNode;
                        break;
                    }

                    crawler = crawler->left;
                }
            }
        }

        return root;
    }
};