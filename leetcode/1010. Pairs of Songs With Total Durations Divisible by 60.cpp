#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int duration = 60;
        int moddedTimes[65];

        memset(moddedTimes, 0, sizeof(moddedTimes));

        for (auto t : time)
        {
            moddedTimes[t % duration]++;
        }

        int ans = 0;
        for (int i = 0; i <= 30; i++)
        {
            if (i == 0 || i == 30)
            {
                ans += (moddedTimes[i] * (moddedTimes[i] - 1)) / 2;
            }
            else
            {
                ans += moddedTimes[i]*moddedTimes[60-i];
            }
        }

        return ans;
    }
};