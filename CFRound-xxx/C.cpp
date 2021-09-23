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

ll getNeed(ll opp, ll total, ll sold, ll opp1)
{
    return max(opp1 - sold, 0LL) + max(opp - (total - sold), 0LL);
}

void solve()
{

    int n, m;
    cin >> n;
    ll hs[n + 5], totalP = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> hs[i];
        totalP += hs[i];
    }

    sort(hs, hs + n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y, need;
        cin >> x >> y;

        int index = upper_bound(hs, hs + n, x) - hs;
        if (index < n)
        {
            if (index == 0)
            {
                need = getNeed(y, totalP, hs[index], x);
            }
            else
            {
                ll lneed = getNeed(y, totalP, hs[index - 1], x);
                ll rneed = getNeed(y, totalP, hs[index], x);
                need = min(lneed, rneed);
            }
        }
        else
        {
            need = getNeed(y, totalP, hs[n - 1], x);
        }

        cout << need << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}