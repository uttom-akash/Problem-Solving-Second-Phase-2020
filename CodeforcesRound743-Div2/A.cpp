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

        reverse(s.begin(), s.end());
        int ans = s[0] - '0';

        for (int i = 1; i < n; i++)
        {
            int num = (s[i] - '0');
            if (num == 0)
                continue;
            ans += num;
            ans++;
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