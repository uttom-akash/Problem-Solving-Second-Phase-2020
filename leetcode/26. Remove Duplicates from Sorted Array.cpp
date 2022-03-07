#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int j = 1;
        int sz = nums.size();

        for (int i = 1; i < sz; i++)
        {
            if (nums[i - 1] != nums[i])
            {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};