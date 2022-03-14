#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long root = x;

        while (root * root > x)
        {
            root = (root + x / root) / 2;
        }

        return root;
    }
};

class Solution2
{
public:
    int mySqrt(int x)
    {
        int lo = 0, hi = x;

        while (lo < hi)
        {
            long mid = (lo + hi + 1) >> 1;

            if (mid * mid > x)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid;
            }
        }

        return lo;
    }
};