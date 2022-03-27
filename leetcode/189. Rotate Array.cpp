#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution2
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int sz = nums.size();
        vector<int> temp(sz);

        for (int i = 0; i < sz; i++)
        {
            temp[(i + k) % sz] = nums[i];
        }

        for (int i = 0; i < sz; i++)
        {
            nums[i] = temp[i];
        }
    }
};

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int sz = nums.size(), indice = 0, start = 0, value = nums[0], canRot = 0;

        while (canRot < sz)
        {
            do
            {
                auto pairIndice = (indice + k) % sz;
                swap(value, nums[pairIndice]);
                indice = pairIndice;
                canRot++;

            } while (indice!=start);

            start++;
            indice = start;
            value = nums[indice];
        }
    }
};