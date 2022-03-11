#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sz = height.size();
        int lmx[sz + 5], rmx[sz + 5];

        lmx[0] = rmx[sz] = 0;

        for (int i = 0; i < sz; i++)
        {
            lmx[i + 1] = max(lmx[i], height[i]);
        }

        for (int i = sz - 1; i >= 0; i--)
        {
            rmx[i] = max(rmx[i + 1], height[i]);
        }

        int ans=0;
        for (int i = 0; i < sz; i++)
        {
            ans+=max(min(lmx[i],rmx[i+1])-height[i],0);
        }

        return ans;
    }
};