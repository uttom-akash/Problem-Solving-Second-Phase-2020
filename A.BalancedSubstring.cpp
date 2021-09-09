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
        string s;
        cin >> n >> s;
        int l = -1, r = -1;
        int N = s.size();

        for (int i = 1; i < N; i++)
        {
            if (s[i - 1] != s[i])
            {
                l = i, r = i + 1;
                break;
            }
        }

        cout << l << " " << r << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}