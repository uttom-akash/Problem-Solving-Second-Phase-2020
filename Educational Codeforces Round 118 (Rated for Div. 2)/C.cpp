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

    for (int tc = 0; tc < ntc; tc++)
    {
        int n;
        ll h;
        cin >> n >> h;

        ll sec[105];

        for (int i = 0; i < n; i++)
        {
            cin >> sec[i];
        }

        sort(sec, sec + n);

        ll lo = 1, hi = h;

        while (lo < hi)
        {
            ll mid = (lo + hi) >> 1;

            ll hitp = 0;

            for (int i = 0; i < n; i++)
            {
                if (i < n - 1)
                    hitp += min(mid, sec[i + 1] - sec[i]);
                else
                    hitp += (mid);
            }

            if (hitp >= h)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}