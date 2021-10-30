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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int sz = intervals.size();
        int lo = INT_MAX, hi = newInterval[1];
        bool insterted = false;
        if (sz > 0 && newInterval[1] < intervals[0][0])
        {
            ans.push_back(newInterval);
            insterted = true;
        }

        for (int i = 0; i < sz; i++)
        {
            if (newInterval[1] < intervals[i][0] || intervals[i][1] < newInterval[0])
            {
                if (lo != INT_MAX)
                {
                    ans.push_back(vector<int>{lo, hi});
                    insterted = true;
                }
                lo = INT_MAX;
            }
            else
            {
                lo = min(lo, newInterval[0]);
                lo = min(lo, intervals[i][0]);
            }

            hi = max(hi, intervals[i][1]);

            if (lo == INT_MAX)
            {
                ans.push_back(vector<int>{intervals[i][0], intervals[i][1]});
            }
        }

        if (lo != INT_MAX)
        {
            ans.push_back(vector<int>{lo, hi});
            insterted = true;
        }

        if (insterted == false)
        {
            ans.push_back(newInterval);
        }

        sort(ans.begin(), ans.end());
        return ans;
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