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

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return node;

        queue<pair<Node *, Node *>> tracker;
        Node *visited[105];

        for (int i = 0; i < 105; i++)
        {
            visited[i] = nullptr;
        }

        Node *root = new Node(node->val);
        tracker.push({node, root});
        visited[node->val] = root;

        while (!tracker.empty())
        {
            auto u = tracker.front();
            tracker.pop();

            for (auto v : u.first->neighbors)
            {
                if (visited[v->val] == nullptr)
                {
                    visited[v->val] = new Node(v->val);
                    tracker.push({v, visited[v->val]});
                }
                u.second->neighbors.push_back(visited[v->val]);
            }
        }

        return root;
    }
};

void solve()
{
}

int main()
{
    optimize();

    solve();

    return 0;
}