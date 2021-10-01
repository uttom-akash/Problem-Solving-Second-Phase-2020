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

void setupFileIO(string fin = "data/input.txt", string fout = "data/Coutput.txt")
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
        int n;
        cin >> n;

        cout << "Case #" << tc << ": " << n << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}