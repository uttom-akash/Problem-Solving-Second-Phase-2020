#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int total = 0;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            total += nums[i];
        }

        if (total & 1)
        {
            return false;
        }

        int half = total >> 1;
        bitset<20002> dp(1);

        for (auto num : nums)
        {
            dp = dp << num | dp;
        }

        return dp[half];
    }
};