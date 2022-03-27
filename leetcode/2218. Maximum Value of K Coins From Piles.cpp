#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

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

    int solveDp(int pileIndex, int k, int n)
    {
        if (k == 0 || pileIndex == n)
            return 0;

        if (dp[pileIndex][k] != -1)
            return dp[pileIndex][k];

        int ans = 0;
        int sz = psum[pileIndex].size();
        for (int take = 0; take <= k and take < sz; take++)
        {
            ans = max(ans, solveDp(pileIndex + 1, k - take, n) + psum[pileIndex][take]);
        }

        dp[pileIndex][k] = ans;

        return ans;
    }
};