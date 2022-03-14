#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{

    vector<vector<int>> ans;
    vector<int> arr;

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
            arr.push_back(0);
        backtrack(nums, sz, 0, 0);

        return ans;
    }

    void backtrack(vector<int> &nums, int n, int pos, short mask)
    {
        if (pos == n)
        {
            ans.push_back(arr);
        }

        for (int i = 0; i < n; i++)
        {
            if ((mask & 1 << i))
                continue;

            arr[pos] = nums[i];
            backtrack(nums, n, pos + 1, mask | 1 << i);
        }
    }
};


class Solution2 {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
    }
};