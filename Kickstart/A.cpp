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

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int n, d;
        ll c, m;
        cin >> n >> d >> c >> m;

        string s;
        cin >> s;

        int nd = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
                nd++;
        }

        bool ans = true;
        for (int i = 0; i < n && nd > 0; i++)
        {
            if (s[i] == 'D')
            {
                d--;
                c += m;
                nd--;
            }
            else
            {
                c--;
            }

            if (d < 0 || c < 0)
            {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "Case #" << tc << ": YES\n";
        else
            cout << "Case #" << tc << ": NO\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}