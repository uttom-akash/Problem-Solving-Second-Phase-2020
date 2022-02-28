#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            Node* prev=nullptr;
            
            for (int i = 0; i < sz; i++)
            {
                auto u = q.front();
                q.pop();

                if(prev){
                    prev->next=u;
                }
                prev=u;
                
                if (u->left)
                    q.push(u->left);

                if (u->right)
                    q.push(u->right);
            }

        }
        return root;
    }
};