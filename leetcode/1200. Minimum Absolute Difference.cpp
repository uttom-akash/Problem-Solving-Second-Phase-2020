#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int minDif = INT_MAX;

        int sz = arr.size();

        for (int i = 0; i + 1 < sz; i++)
        {
            minDif = min(minDif, arr[i + 1] - arr[i]);
        }

        vector<vector<int>> ans;

        for (int i = 0; i + 1 < sz; i++)
        {
            if (arr[i + 1] - arr[i] == minDif)
                ans.push_back({arr[i], arr[i + 1]});
        }

        return ans;
    }
};