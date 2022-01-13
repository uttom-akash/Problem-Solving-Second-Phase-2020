#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);

        int last = points[0][1];
        int ans=1;

        for (auto p : points)
        {
            if(last>=p[0])
                continue;
            
            last = p[1];
            ans++;
        }
        
        return ans;
    }

    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if(a[1]<b[1])
            return true;
        if(a[1]==b[1] && a[0]<b[0])
            return true;

        return false;
    }
};