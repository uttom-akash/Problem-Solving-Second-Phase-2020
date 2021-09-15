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

        int prevI = -1, nSwitch[150 + 5], dSwitch[150 + 5], firstSwitch = -1;
        for (int i = 0; i < N; i++)
        {
            nSwitch[i] = 0;
            dSwitch[i] = 0;
        }

        for (int i = 0; i < N; i++)
        {
            if (W[i] == 'F')
                continue;

            if (prevI != -1 && W[prevI] != W[i])
            {
                nSwitch[i]++;
                dSwitch[prevI + 1]++;
                if (firstSwitch == -1)
                    firstSwitch = i;
            }
            prevI = i;
        }

        for (int i = 1; i < N; i++)
        {
            nSwitch[i] = (nSwitch[i] + nSwitch[i - 1]) % mod;
            dSwitch[i] = (dSwitch[i] + dSwitch[i - 1]) % mod;
        }

        // for (int i = 1; i < N; i++)
        // {
        //     dSwitch[i] = ((ll)dSwitch[i] + dSwitch[i - 1]) % mod;
        // }

        int ans = 0;
        for (int i = 1; i < N; i++)
        {
            // ans = ((ll)ans + ((ll)i * nSwitch[i]) % mod) % mod;
            // ans = ((ans - dSwitch[i - 1]) % mod + mod) % mod;
            for (int j = 0; j < i; j++)
            {
                if (nSwitch[i] < dSwitch[j])
                    continue;
                ans = (0LL + ans + nSwitch[i] - dSwitch[j]) % mod;
                if (ans < 0)
                    ans %= mod;
            }
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