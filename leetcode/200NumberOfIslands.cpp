#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long
#define way4                               \
    (int[4][2])                            \
    {                                      \
        {0, 1}, {1, 0}, {0, -1}, { -1, 0 } \
    }

#define way8                                                                   \
    (int[8][2])                                                                \
    {                                                                          \
        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, { -1, 1 } \
    }

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
public:
    int numIslands(vector<vector<char>> &grid)
    {

        int N = grid.size();
        int M = grid[0].size();

        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    grid[i][j] = '0';

                    while (!st.empty())
                    {
                        auto cur = st.top();
                        st.pop();

                        for (int nxt = 0; nxt < 4; nxt++)
                        {
                            auto nxtI = cur.first + way4[nxt][0];
                            auto nxtJ = cur.second + way4[nxt][1];

                            if (nxtI >= 0 && nxtI < N && nxtJ >= 0 && nxtJ < M && grid[nxtI][nxtJ] == '1')
                            {
                                grid[nxtI][nxtJ] = '0';
                                st.push({nxtI, nxtJ});
                            }
                        }
                    }
                }
            }
        }

        return ans;
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