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
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {

        int sz = security.size();
        vector<int> ans;
        if (time == 0)
        {
            for (int i = 0; i < sz; i++)
            {
                ans.push_back(i);
            }

            return ans;
        }
        int inc[10 + 5], dec[10 + 5];
        inc[0] = 0;
        dec[0] = 0;
        for (int i = 1; i < sz; i++)
        {
            if (security[i - 1] <= security[i])
            {
                inc[i] = inc[i - 1] + 1;
            }
            else
            {
                inc[i] = inc[i - 1] - 1;
            }

            if (security[i - 1] >= security[i])
            {
                dec[i] = dec[i - 1] + 1;
            }
            else
            {
                dec[i] = dec[i - 1] - 1;
            }
        }

        for (int i = time; i + time < sz; i++)
        {
            int d = dec[i] - dec[i - time];

            int bar = inc[i + time] - inc[i];

            if (d == time && bar == time)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

void solve()
{

    Solution s;
    vector<int> a({1, 2, 5, 4, 1, 0, 2, 4, 5, 3, 1, 2, 4, 3, 2, 4, 8});
}

int main()
{
    optimize();

    solve();

    return 0;
}