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
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int sz = nums.size();
        vector<vector<int>> allsubsets;

        for (int i = 0; i < 1 << sz; i++)
        {
            vector<int> csubset;
            for (int j = 0; j < sz; j++)
            {
                if (i & 1 << j)
                {
                    csubset.push_back(nums[j]);
                }
            }
            allsubsets.push_back(csubset);
        }

        return allsubsets;
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