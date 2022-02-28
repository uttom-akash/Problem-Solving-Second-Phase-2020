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

class Solution
{
public:
    bool takeOne(int i, string s, int n)
    {
        if (s[i] == '0')
            return false;
        if (i + 1 < n && s[i + 1] == '0')
            return false;

        return true;
    }

    bool takeTwo(int i, string s, int n)
    {
        if (i + 1 >= n)
            return false;

        if (s[i] == '0' || s[i] - '0' > 2 || (s[i] == '2' && s[i + 1] - '0' > 6))
            return false;

        if (i + 2 < n && s[i + 2] == '0')
            return false;

        return true;
    }

    int numDecodings(string s)
    {
        int n = s.size();
        unsigned int ans = 1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && (i - 1 < 0 || s[i - 1] - '0' > 2))
            {
                return 0;
            }

            if (takeOne(i, s, n) && takeTwo(i, s, n))
                ans++;
                }

        return ans;
    }
};

void setupFileIO(string fin = "input.txt", string fout = "output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

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