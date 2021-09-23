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
        int n;
        cin >> n;
        int odd[n + 5], even[n + 5];

        for (int i = 0; i < n; i++)
            cin >> odd[i];

        int emax = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> even[i];
            even[i] = max(emax, even[i]);
            emax = max(emax, even[i]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int pos = upper_bound(even, even + n, odd[i]) - even;
            ans = min(ans, i + pos);
        }

        cout << ans << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}