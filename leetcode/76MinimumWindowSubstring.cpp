#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define N 100
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
    string minWindow(string s, string t)
    {
        int mapper[N];
        int tN = t.size(), sN = s.size();
        memset(mapper, 0, sizeof mapper);

        for (int i = 0; i < tN; i++)
        {
            int index = t[i] - 'A';
            mapper[index]++;
        }

        int lo = 0, hi = 0, ans = INT_MAX, rlo, rhi;
        bool LH = false;
        while (hi < sN)
        {
            if (LH)
            {
                int index = s[lo - 1] - 'A';
                mapper[index]++;
            }
            else
            {
                int index = s[hi] - 'A';
                mapper[index]--;
            }

            auto isAll = isAllIn(mapper);

            if (isAll && ans > (hi - lo + 1))
            {
                ans = hi - lo + 1;
                rlo = lo, rhi = hi;
            }

            if (lo < hi && isAll)
            {
                lo++;
                LH = true;
            }
            else
            {
                hi++;
                LH = false;
            }
        }
        if (ans == INT_MAX)
            return "";
        else
            return s.substr(rlo, rhi - rlo + 1);
    }

    bool isAllIn(int mapper[])
    {
        for (int i = 0; i < N; i++)
        {
            if (mapper[i] > 0)
                return false;
        }

        return true;
    }
};

void solve()
{
    Solution s;
    s.minWindow("ADOBECODEBANC", "ABC");
}

int main()
{
    optimize();

    solve();

    return 0;
}