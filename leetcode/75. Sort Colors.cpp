#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size());
    }

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return;
        }

        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int n = right - left + 1;

        int temp[n + 5];

        int i = left, j = mid + 1;
        for (int k = 0; k < n; k++)
        {
            if (j > right || (i <= mid && nums[i] < nums[j]))
            {
                temp[k] = nums[i++];
            }
            else
            {
                temp[k] = nums[j++];
            }
        }

        for (int k = 0; k < n; k++)
        {
            nums[left + k] = temp[k];
        }
    }
};

class Solution2
{
public:
    void sortColors(vector<int> &nums)
    {
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while (mid <= hi)
        {
            switch (nums[mid])
            {
            case 0:
                swap(nums[lo++],nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid],nums[hi--]);
                break;
            }
        }
    }
};