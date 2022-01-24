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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        map<int, vector<vector<int>>> ans;

        int sz = nums.size();

        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                int sm = nums[i] + nums[j];
                ans[sm].push_back(vector<int>({nums[i], nums[j], j + 1}));
            }
        }

        for (auto sm : ans)
        {
            int ssz = sm.second.size();
            for (int i = 0; i < ; i++)
            {
                /* code */
            }
        }
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