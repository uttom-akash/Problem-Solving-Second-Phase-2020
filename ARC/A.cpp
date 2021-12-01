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

    ll n, l, r;
    cin >> n >> l >> r;

    ll ans = 0;

    for (ll i = 63; i >= 0; i--)
    {
        if (n & 1LL << i)
        {
            ll li = 1LL << i;
            ll ri = (1LL << (i + 1)) - 1;

            ans = ans + max(min(r, ri) - max(l, li) + 1LL, 0LL);
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