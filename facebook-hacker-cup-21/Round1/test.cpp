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

void setupFileIO(string fin = "data/input.txt", string fout = "data/testOutput.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

int A1(int N, string W)
{
    int nSwitch = 0;
    int prevI = -1;

    for (int i = 0; i < N; i++)
    {
        if (W[i] == 'F')
            continue;

        if (prevI != -1 && W[prevI] != W[i])
            nSwitch++;

        prevI = i;
    }

    return nSwitch;
}

int A2(int N, string W)
{

    ll ans = 0;
    for (int k = 1; k <= N; k++)
    {
        for (int i = 0; i + k - 1 < N; i++)
        {
            string s = W.substr(i, k);
            ll ia = A1(k, s);
            ans = (ans + ia);
        }
    }
    return ans;
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

        int ans = A2(N, W);

        cout << "ans: " << ans << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}
