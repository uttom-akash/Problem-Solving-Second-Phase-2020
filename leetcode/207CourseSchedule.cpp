#include <bits/stdc++.h>

#define mx 100005
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
public:
    vector<int> adj[mx];
    int indeg[mx], visited[mx];

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int N = prerequisites.size();
        memset(indeg, 0, numCourses);
        memset(visited, 0, numCourses);

        for (size_t i = 0; i < N; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }

        stack<int> tracker;
        for (size_t i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                visited[i] = 1;
                tracker.push(i);
            }
        }

        while (!tracker.empty())
        {
            auto u = tracker.top();
            tracker.pop();

            for (auto v : adj[u])
            {
                indeg[v]--;
                if (!visited[v] && !indeg[v])
                {
                    visited[v] = 1;
                    tracker.push(v);
                }
            }
        }

        for (size_t i = 0; i < numCourses; i++)
        {
            if (!visited[i])
                return false;
        }

        return true;
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    Solution s;
    vector<vector<int>> pre({{1, 0}});
    s.canFinish(2, pre);
}

int main()
{
    optimize();

    solve();

    return 0;
}