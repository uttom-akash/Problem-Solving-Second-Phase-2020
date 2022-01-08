#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int sz = nums.size();
        int length[1005] = {0};
        int parent[1005] = {0};

        for (int i = 0; i < sz; i++)
        {
            length[i] = 1;
            parent[i] = i;
        }

        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                if (isValidTransition(nums[i], nums[j]))
                {
                    if (length[i] + 1 > length[j])
                    {
                        length[j] = length[i] + 1;
                        parent[j] = i;
                    }
                }

                if (length[j] > length[sz])
                {
                    length[sz] = length[j];
                    parent[sz] = j;
                }
            }
        }

        vector<int> ans;
        int i = sz;
        while (parent[i] != i)
        {
            ans.push_back(nums[parent[i]]);
            i = parent[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool isValidTransition(int a, int b)
    {
        return a % b == 0 || b % a == 0;
    }
};