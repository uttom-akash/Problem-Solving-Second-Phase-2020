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

class Solution
{
    vector<short> adjMatrix[1005];
    int indegree[1005];
    set<short> ancestors[1005];

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        memset(indegree, 0, sizeof(indegree));

        for (auto e : edges)
        {
            adjMatrix[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            vector<int> a(ancestors[i].begin(), ancestors[i].end());
            ans.push_back(a);
        }

        return ans;
    }

    void doTopSort(int n)
    {
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto v : adjMatrix[u])
            {
                indegree[v]--;
                ancestors[v].insert(u);
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());


                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }
};

void solve()
{

    Solution s;
    vector<int>
        s.getAncestors()
}

int main()
{
    optimize();

    solve();

    return 0;
}