#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

// | i | 0 | 1 | 2 | 3 | i
// 0   1   2   3   4   5
// n=1,m=1
// 0
// 1
// i | 0 | i
// i | 1 | i

class Solution
{
public:
    int getValue(vector<int> &nums, int sz, int index)
    {
        if (index < 0)
            return INT_MIN;
        if (index >= sz)
            return INT_MAX;

        return nums[index];
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        int lo = 0, hi = n;
        int firstHalfSz = (n + m + 1) / 2;
        double ans = 0.00;

        while (lo <= hi)
        {
            int mid1 = (lo + hi) >> 1;

            int mid2 = firstHalfSz - mid1;

            if (getValue(nums1, n, mid1 - 1) > getValue(nums2, m, mid2))
            {
                hi = mid1 - 1;
            }
            else if (getValue(nums2, m, mid2 - 1) > getValue(nums1, n, mid1))
            {
                lo = mid1 + 1;
            }
            else
            {
                ans = max(getValue(nums1, n, mid1 - 1), getValue(nums2, m, mid2 - 1));
                if (((n + m) & 1) == 0)
                {
                    ans += min(getValue(nums2, m, mid2), getValue(nums1, n, mid1));
                    ans/=2.00;
                }
                break;
            }
        }

        return ans;
    }
};