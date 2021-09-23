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

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        int a, b, c, m;
        cin >> a >> b >> c >> m;

        int bad = 0;

        if (a > 1 && m > 0)
        {
            bad = min(a - 1, m);
            m -= bad;
            a -= bad;
        }

        if (b > 1 && m > 0)
        {
            bad = min(b - 1, m);
            m -= bad;
            b -= bad;
        }

        if (c > 1 && m > 0)
        {
            bad = min(c - 1, m);
            m -= bad;
            c -= bad;
        }

        if (m > 0 || a + b < c || b + c < a || c + a < b)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}