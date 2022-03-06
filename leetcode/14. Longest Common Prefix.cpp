#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        return DnQ(strs,0,strs.size()-1);
    }

    string DnQ(vector<string> &strs, short lo, short hi)
    {
        if (lo == hi)
        {
            return strs[lo];
        }

        short mid = (lo + hi) >> 1;

        auto lst = DnQ(strs, lo, mid);
        auto rst = DnQ(strs, mid + 1, hi);

        return getCommonPrefix(lst, rst);
    }

    string getCommonPrefix(string a, string b)
    {
        int n = a.size();
        int m = b.size();

        int l = min(n, m);

        int i = 0;
        string commonPrefix = "";
        
        while (i < l and a[i] == b[i])
        {
            commonPrefix += a[i];
            i++;
        }

        return commonPrefix;
    }
};