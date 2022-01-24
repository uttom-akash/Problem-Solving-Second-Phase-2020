#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

// fill_n(&a[0][0], ntc * ntc, -100);

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
    int combinationSum4(vector<int> &nums, int target)
    {
        int targets[target + 5];
        int n = nums.size();

        memset(targets, 0, sizeof(targets));
        targets[0] = 1;

        for (int sum = 1; sum <= target; sum++)
        {
            for (int i = 0; i < n; i++)
            {

                if (sum - nums[i] >= 0)
                {
                    targets[sum] += targets[sum - nums[i]] + 1;
                }
            }
        }

        return targets[target];
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        string s;
        cin >> s;
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}