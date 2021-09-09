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
    int characterReplacement(string s, int k)
    {
        int N = s.size();
        int mapper[N + 5][30];
        memset(mapper, 0, sizeof mapper);

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                mapper[i][j] = mapper[i - 1][j];
            }

            int ctoI = s[i - 1] - 'A';
            mapper[i][ctoI]++;
        }

        int lo = 0, hi = 1, ans = 0;

        while (hi <= N)
        {
            int mxSame = 0;
            for (int j = 0; j < 26; j++)
            {
                mxSame = max(mapper[hi][j] - mapper[lo][j], mxSame);
            }

            int needReplace = hi - lo - mxSame;
            if (needReplace <= k || lo + 1 == hi)
            {
                ans = max(ans, hi - lo);
                hi++;
            }
            else
                lo++;
        }

        return ans;
    }
};

void solve()
{
    Solution s;
    s.characterReplacement("AABABBA", 1);
}

int main()
{
    optimize();

    solve();

    return 0;
}