#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    pair<int,int> applyManchers(string s)
    {
        int n = s.size();
        string pS = "#";
        for (int i = 0; i < n; i++)
        {
            pS += s[i];
            pS += "#";
        }

        int N = pS.size(), center = 0, right = 0;
        int Z[N + 5];
        memset(Z, 0, sizeof Z);

        int longestPalSz = 0, longestPalCent;

        for (int i = 0; i < N; i++)
        {
            if (i < right)
                Z[i] = min(right - i, Z[2 * center - i]);

            while (i + Z[i] + 1 < N && i - Z[i] - 1 >= 0 && pS[i + Z[i] + 1] == pS[i - Z[i] - 1])
            {
                Z[i]++;
            }

            if (i + Z[i] > right)
            {
                center = i;
                right = i + Z[i];
            }

            if (longestPalSz < Z[i])
            {
                longestPalSz = Z[i];
                longestPalCent = i;
            }
        }

        return {(longestPalCent-longestPalSz)/2,longestPalSz};

    }

    string longestPalindrome(string s)
    {
        auto result = applyManchers(s);

        return s.substr(result.first,result.second);
    }
};
