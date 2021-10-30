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
        int n, k;
        cin >> n >> k;

        int mice[k + 5];

        for (int i = 0; i < k; i++)
        {
            cin >> mice[i];
        }

        sort(mice, mice + k, greater<int>());

        int ans = 0, tempp = n;

        for (int i = 0; i < k; i++)
        {
            int path = tempp - mice[i];
            if (n > path)
            {
                n -= path;
                ans++;
            }
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
