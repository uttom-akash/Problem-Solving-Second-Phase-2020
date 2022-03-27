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
    int dp[1005][2005];
    vector<int> psum[1005];

public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        memset(dp, -1, sizeof(dp));

        int sz = piles.size();
        for (int i = 0; i < sz; i++)
        {
            psum[i].push_back(0);
            for (int j = 0; j < piles[i].size(); j++)
            {
                psum[i].push_back(0);
                psum[i][j + 1] += psum[i][j];
                psum[i][j + 1] += piles[i][j];
            }
        }

        return solveDp(0, k, sz);
    }

    int solveDp(int pileI, int k, int n)
    {
        if (k == 0 || pileI == n)
            return 0;

        if (dp[pileI][k] != -1)
            return dp[pileI][k];

        int ans = 0, take = 0;
        while (take <= k and take < psum[pileI].size())
        {
            ans = max(ans, solveDp(pileI + 1, k - take, n) + psum[pileI][take]);
            take++;
        }

        dp[pileI][k] = ans;
        return ans;
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}