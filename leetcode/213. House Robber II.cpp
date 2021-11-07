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
public:
    int rob(vector<int> &nums)
    {
        int sz = nums.size();
        int ans = nums[0];
        ans = max(ans, doCal(nums, 1, sz - 1));
        ans = max(ans, doCal(nums, 2, sz));

        return ans;
    }

    int doCal(vector<int> &nums, int l, int r)
    {
        int dp[2][r + 5];

        memset(dp, 0, sizeof(dp));

        for (int i = l; i <= r; i++)
        {
            int amnt = nums[i - 1];
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = dp[0][i - 1] + amnt;
        }

        return max(dp[0][r], dp[1][r]);
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