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
    pair<int, int> getMappedRC(int index, int col)
    {
        return {index / col, (index % col)};
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m * n;

        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;
            auto rc = getMappedRC(mid, n);

            if (matrix[rc.first][rc.second] >= target)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        auto arc = getMappedRC(lo, n);
        return matrix[arc.first][arc.second] == target;
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