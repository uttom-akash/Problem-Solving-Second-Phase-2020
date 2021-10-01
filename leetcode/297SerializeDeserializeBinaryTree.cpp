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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    pair<int, int> getVal(int start, string s)
    {
        int n = s.size(), i;
        int val = 0;
        for (i = start; i < n; i++)
        {
            if (s[i] == ' ')
            {
                i++;
                break;
            }
            if (s[i] == '|')
            {
                i += 2;
                return {i, NULL};
            }

            val *= 10;
            val += s[i] - '0';
        }

        return {i, val};
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s = "";
        stack<TreeNode *> tracker;
        tracker.push(root);

        while (!tracker.empty())
        {
            auto u = tracker.top();
            tracker.pop();

            if (u == nullptr)
            {
                s = s + "|" + " ";
                continue;
            }

            s = s + to_string(u->val) + " ";

            tracker.push(u->right);

            tracker.push(u->left);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stack<TreeNode *> tracker;
        TreeNode *root = NULL;
        tracker.push(root);
        int i = 0;
        bool first = true;

        while (!tracker.empty())
        {
            auto u = tracker.top();
            tracker.pop();

            auto valuePair = getVal(i, data);
            i = valuePair.first;

            if (valuePair.second == NULL)
            {
                continue;
            }

            *&u = new TreeNode(valuePair.second);

            tracker.push(*&u->right);

            tracker.push(*&u->left);
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