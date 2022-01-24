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
    int bulbSwitch(int n)
    {
        int ans = 0, round = n;

        if (round-- > 0)
        {
            ans = n;
        }

        if (round-- > 0)
        {
            ans -= (n / 2);
        }

        if (round-- > 0)
        {
            ans -= (n / 3);
            ans += (n / 6);
        }

        if (round > 0)
        {
            ans = (n - 3) - (ans - 1);
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