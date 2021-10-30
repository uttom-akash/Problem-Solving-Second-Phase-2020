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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TrackInfo
{
    int lo, hi;
    TreeNode **node;
    TrackInfo(int lo, int hi, TreeNode **node)
    {
        this->lo = lo;
        this->hi = hi;
        this->node = node;
    }
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        stack<TrackInfo> tracker;
        map<int, int> inorderMapper;
        TreeNode *root;
        tracker.push(TrackInfo(0, n - 1, &root));
        int preorderShift = 0;

        for (size_t i = 0; i < n; i++)
        {
            inorderMapper[inorder[i]] = i;
        }

        while (!tracker.empty())
        {
            auto info = tracker.top();

            tracker.pop();

            int nroot = inorderMapper[preorder[preorderShift++]];

            *info.node = new TreeNode(inorder[nroot]);

            if (nroot < info.hi)
            {
                tracker.push(TrackInfo(nroot + 1, info.hi, &(*info.node)->right));
            }

            if (info.lo < nroot)
            {
                tracker.push(TrackInfo(info.lo, nroot - 1, &(*info.node)->left));
            }
        }

        return root;
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        string s;
        cin >> s;
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}