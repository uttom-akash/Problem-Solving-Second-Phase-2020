#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        // long divd = abs(dividend), divisr = abs(divisor);

        dividend = abs(dividend);
        divisor = abs(divisor);
        long ans = 0;

        while (divisor <= dividend)
        {
            long subt = divisor;
            long ia = 1;

            while ((subt << 1) <= dividend)
            {
                subt <<= 1; // subt+=subt
                ia <<= 1;   // ia+=ia
            }

            dividend -= subt;
            ans += ia;
        }

        ans=sign * ans;

        if(ans<INT_MIN)ans=INT_MIN;
        if(ans>INT_MAX)ans=INT_MAX;
        return ans;
    }
};
