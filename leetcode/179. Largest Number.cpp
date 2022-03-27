#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    static bool comp(string &a, string &b)
    {
        return a + b >= b + a;
    }

    string largestNumber(vector<int> &nums)
    {
        vector<string> numsStr;
        for (auto num : nums)
        {
            numsStr.push_back(to_string(num));
        }

        sort(numsStr.begin(), numsStr.end(), comp);

        string ans = "";
        for (auto num : numsStr)
        {
            if (num == "0" && ans == "0")
                continue;

            ans += num;
        }

        return ans;
    }
};