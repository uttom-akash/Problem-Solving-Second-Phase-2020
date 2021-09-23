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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int N = intervals.size();
        sort(intervals.begin(), intervals.end());
        stack<pair<int, int>> selected;

        for (size_t i = 0; i < N; i++)
        {
            int a = intervals[i][0], b = intervals[i][1];
            if (selected.empty())
            {
                selected.push({intervals[i][0], intervals[i][1]});
            }
            else
            {
                if (selected.top().second > intervals[i][0] && selected.top().second > intervals[i][1])
                {
                    selected.pop();
                    selected.push({intervals[i][0], intervals[i][1]});
                }
                else if (selected.top().second <= intervals[i][0])
                {
                    selected.push({intervals[i][0], intervals[i][1]});
                }
            }
        }
        return N - selected.size();
    }
};

void solve()
{

    Solution s;
    vector<vector<int>> v({{1, 2}, {2, 3}, {3, 4}, {1, 3}});
    s.eraseOverlapIntervals(v);
}

int main()
{
    optimize();

    solve();

    return 0;
}