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

void setupFileIO(string fin = "data/weak_typing_chapter_1_input (1).txt", string fout = "data/A1output.txt")
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
        int N, nSwitch = 0;
        string W;
        cin >> N >> W;

        int prevI = -1;

        for (int i = 0; i < N; i++)
        {
            if (W[i] == 'F')
                continue;

            if (prevI != -1 && W[prevI] != W[i])
                nSwitch++;

            prevI = i;
        }

        cout << "Case #" << tc << ": " << nSwitch << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}