#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int sz = nums.size();

        for (size_t i = 0; i < sz; i++)
        {
            while (nums[i] > 0 and nums[i] <= sz and nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (size_t i = 0; i < sz; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return sz + 1;
    }
};