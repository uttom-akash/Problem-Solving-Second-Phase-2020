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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        stack<pair<int, int>> merged;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (!merged.empty())
            {
                auto top = merged.top();
                if (top.first <= intervals[i][0] && intervals[i][1] <= top.second)
                    continue;

                if (top.second >= intervals[i][0])
                {
                    intervals[i][0] = top.first;
                    merged.pop();
                }
            }

            merged.push({intervals[i][0], intervals[i][1]});
        }
        intervals.clear();

        while (!merged.empty())
        {
            auto top = merged.top();
            merged.pop();
            intervals.push_back(vector<int>({top.first, top.second}));
            cout << top.first << " " << top.second << "\n";
        }

        return intervals;
    }
};

void solve()
{
    vector<vector<int>> v({{1, 2}, {3, 4}, {1, 8}});
    auto solution = new Solution();
    auto intervals = solution->merge(v);
}

int main()
{
    optimize();

    solve();

    return 0;
}