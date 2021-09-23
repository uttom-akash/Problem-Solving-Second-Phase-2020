

#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

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
    int way4[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool visited[205][205];
    int nodeStates[205][205];
    vector<vector<int>> both;
    int m, n;

public:
    void dfs(vector<vector<int>> &heights, int ur, int uc, int ocean)
    {
        visited[ur][uc] = true;
        nodeStates[ur][uc] |= ocean;
        for (size_t i = 0; i < 4; i++)
        {
            int vr = ur + way4[i][0];
            int vc = uc + way4[i][1];

            if (vr < 0 || vc < 0 || vr >= m || vc >= n)
            {
                continue;
            }
            if (heights[ur][uc] <= heights[vr][vc])
            {
                if (!visited[vr][vc])
                {
                    dfs(heights, vr, vc, ocean);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                visited[i][j] = false;
                nodeStates[i][j] = 0;
            }
        }

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (!visited[i][j] && (i == 0 || j == 0))
                {
                    dfs(heights, i, j, 1);
                }
            }
        }

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (!visited[i][j] && (i == m - 1 || j == n - 1))
                {
                    dfs(heights, i, j, 2);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nodeStates[i][j] == 3)
                {
                    both.push_back({i, j});
                }
            }
        }
        return both;
    }
};

void solve()
{

    Solution s;
    vector<vector<int>> v({{3, 3, 3}, {3, 1, 3}, {0, 2, 4}});
    s.pacificAtlantic(v);
}

int main()
{
    optimize();

    solve();

    return 0;
}