

#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long
#define way4                               \
    (int[4][2])                            \
    {                                      \
        {0, 1}, {1, 0}, {0, -1}, { -1, 0 } \
    }

//fill_n(&a[0][0], ntc * ntc, -100);

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
private:
    int dp[105][105];

public:
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        dp[m - 1][n - 1] = 1;

        return dfs(0, 0, m, n);
    }

    int dfs(int ui, int uj, int m, int n)
    {
        dp[ui][uj] = 0;

        for (int i = 0; i < 2; i++)
        {
            int vi = ui + way4[i][0];
            int vj = uj + way4[i][1];

            if (vi >= m || vi < 0 || vj >= n || vj < 0)
                continue;

            if (dp[vi][vj] == -1)
            {
                dp[ui][uj] += dfs(vi, vj, m, n);
            }
            else
            {
                dp[ui][uj] += dp[vi][vj];
            }
        }

        return dp[ui][uj];
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