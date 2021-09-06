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
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prefixProduct = 1, zeroCnt = 0;
        int cnt = nums.size();

        for (int i = 0; i < cnt; i++)
        {
            if (nums[i] == 0)
            {
                zeroCnt++;
                continue;
            }

            prefixProduct *= nums[i];
        }

        for (int i = 0; i < cnt; i++)
        {
            if (zeroCnt == 1)
            {
                if (nums[i] == 0)
                {
                    nums[i] = prefixProduct;
                }
                else
                {
                    nums[i] = 0;
                }
            }
            else if (zeroCnt > 1)
                nums[i] = 0;
            else
                nums[i] = prefixProduct / nums[i];

            cout << nums[i] << "\n";
        }

        return nums;
    }
};

void solve()
{
    vector<int> nums({-1, 1, 0, -3, 3});
    Solution sol;
    sol.productExceptSelf(nums);
}

int main()
{
    optimize();

    solve();

    return 0;
}