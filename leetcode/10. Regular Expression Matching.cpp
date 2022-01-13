#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
private:
    string st, pat;
    int l1, l2;
    short dp[25][35];

public:
    bool isMatch(string s, string p)
    {
        st = s, pat = p;
        l1 = s.size();
        l2 = p.size();
        memset(dp, -1, sizeof(dp));
        if (calc(0, 0) == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int calc(int i, int j)
    {
        if(j==l2){
            if(i==l1) return 1;
            else return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];


        int ans = 0;
        if (j + 1 < l2 && pat[j + 1] == '*')
        {
            ans = calc(i, j + 1);
        }
        else if (j < l2 && pat[j] == '*')
        {
            ans = calc(i, j + 1);

            if (i<l1 && pat[j - 1] == '.' || st[i] == pat[j - 1])
            {
                ans |= calc(i + 1, j);
            }
        }
        else if (i<l1 && j<l2 && pat[j] == '.' || st[i] == pat[j])
        {
            ans = calc(i + 1, j + 1);
        }
        dp[i][j] = ans;

        return ans;
    }
};