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
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mapper;
        int N = s.size();
        int lo = 0, hi = 0, ans = 0;

        while (hi < N)
        {
            auto cur = s[hi];
            mapper[cur]++;
            while (lo < hi && mapper[cur] > 1)
            {
                mapper[s[lo]]--;
                lo++;
            }
            ans = max(ans, hi - lo + 1);
            hi++;
        }

        return ans;
    }
};

void solve()
{
    Solution s;
    s.lengthOfLongestSubstring("");
}

int main()
{
    optimize();

    solve();

    return 0;
}