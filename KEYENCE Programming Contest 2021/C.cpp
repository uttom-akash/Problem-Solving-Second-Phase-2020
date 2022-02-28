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

    ll n;
    cin >> n;
    ll ans = 0;

    for (int i = 1; i * i * i <= n; i++)
    {
        if (n % i != 0)
        {
            continue;
        }

        for (int j = i; i * j * j <= n; j++)
        {
            if (n % (1LL * i * j) != 0)
            {
                continue;
            }

            for (int k = j; i * j * k <= n; k++)
            {
                if (n % (1LL * i * j * k) != 0)
                {
                    continue;
                }

                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}