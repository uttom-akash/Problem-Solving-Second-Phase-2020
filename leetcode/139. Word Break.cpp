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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int sz = s.size();
        int sz1 = wordDict.size();
        int segments[sz + 5];
        memset(segments, 0, sizeof(segments));
        segments[0] = 1;

        for (int i = 1; i <= sz; i++)
        {
            for (int j = 0; j < sz1; j++)
            {
                int wordSz = wordDict[j].size();
                if (i < wordSz)
                    continue;

                auto lastBytes = s.substr(i - wordSz, wordSz);

                if (lastBytes == wordDict[j])
                {
                    segments[i] |= segments[i - wordSz];
                }
            }
        }

        return segments[sz];
    }
};

void solve()
{
}

int main()
{
    optimize();

    solve();

    return 0;
}