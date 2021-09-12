#include <bits/stdc++.h>

#define mx 10000
#define mod 1000000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "data/weak_typing_chapter_2_validation_input.txt", string fout = "data/A2output.txt")
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
        int N;
        string W;
        cin >> N >> W;

        ll nSwitch[N + 5], rSwitch[N + 5];
        memset(nSwitch, 0, sizeof nSwitch);
        memset(rSwitch, 0, sizeof rSwitch);

        int prevI = -1;

        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                nSwitch[i] = nSwitch[i - 1];

            if (W[i] == 'F')
                continue;

            if (prevI != -1 && W[prevI] != W[i])
            {
                nSwitch[i]++;
                rSwitch[prevI + 1]++;
            }

            prevI = i;
        }

        for (int i = 1; i < N; i++)
        {
            rSwitch[i] += rSwitch[i - 1];
        }

        for (int i = 1; i < N; i++)
        {
            rSwitch[i] = (rSwitch[i] + rSwitch[i - 1]) % mod;
        }

        ll ans = 0;
        for (ll i = 1; i < N; i++)
        {
            ll total = (i * nSwitch[i]) % mod, sbSwitch = 0;
            if (total > rSwitch[i - 1])
                sbSwitch = total - rSwitch[i - 1];

            ans = (ans + sbSwitch) % mod;
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}