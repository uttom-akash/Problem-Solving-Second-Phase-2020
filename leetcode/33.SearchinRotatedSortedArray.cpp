#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "input.txt", string fout = "output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

class Solution
{

    /**
     * [0,1,2,4,5,6,7] rot = 3
     * [4,5,6,7,0,1,2]
     * 
     * (0-3)%7 => -3%7 => 4, (4+3)%7 => 7 % 7 =>0  
     * 
     * 0,1,2,3
     * 1,2,3,0
     * 
     * */

public:
    int search(vector<int> &nums, int target)
    {
        int k = 0;
        int cnt = nums.size();
        for (int i = 1; i < cnt; i++)
        {
            if (nums[i - 1] > nums[i])
                k = cnt - i;
        }

        int index = getIndex(nums, target, k);
        return index;
    }

    int getRotatedIndex(int index, int rotation, int N)
    {
        int res = (index - rotation + N) % N;
        return res;
    }

    int getIndex(vector<int> &nums, int target, int rotation)
    {
        int N = nums.size();
        int lo = 0, hi = N - 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (target <= nums[getRotatedIndex(mid, rotation, N)])
                hi = mid;
            else
                lo = mid + 1;
        }

        if (nums[getRotatedIndex(lo, rotation, N)] == target)
            return getRotatedIndex(lo, rotation, N);
        else
            return -1;
    }
};

void solve()
{
    Solution s;
    vector<int> v({4, 5, 6, 7, 0, 1, 2});
    cout << s.search(v, 0) << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}