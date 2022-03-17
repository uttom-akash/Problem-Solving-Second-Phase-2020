#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int maxima = INT_MIN, maxIndex = 0, diffSum = 0, sz = gas.size();

        for (int i = sz - 1; i >= 0; i--)
        {
            diffSum = diffSum + (gas[i] - cost[i]);
            if (diffSum > maxima)
            {
                maxima = diffSum, maxIndex = i;
            }
        }

        int remGas = 0;
        for (int i = 0; i < sz; i++)
        {
            int j = (i + maxIndex) % sz;
            remGas += gas[j];
            remGas -= cost[j];

            if (remGas < 0)
                return -1;
        }
        return maxIndex;
    }
};