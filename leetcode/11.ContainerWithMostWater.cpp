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
    int maxArea(vector<int> &height)
    {
        int N = height.size();
        int ans = 0;

        int lo = 0, hi = N - 1;
        while (lo < hi)
        {
            ans = max(ans, (hi - lo) * min(height[hi], height[lo]));

            if (height[lo] < height[hi])
                lo++;
            else
                hi--;
        }

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