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
        int a, b, c;
        cin >> a >> b >> c;

        int mxVotes = max(a, max(b, c));
        int cnt = 0;
        if (mxVotes == a)
            cnt++;

        if (mxVotes == b)
            cnt++;

        if (mxVotes == c)
            cnt++;

        if (cnt > 1)
            cout << max(0, mxVotes - a + 1) << " "
                 << max(0, mxVotes - b + 1) << " "
                 << max(0, mxVotes - c + 1) << "\n";
        else
            cout << max(0, (mxVotes - a + (mxVotes == a ? 0 : 1))) << " "
                 << max(0, (mxVotes - b + (mxVotes == b ? 0 : 1))) << " "
                 << max(0, (mxVotes - c + (mxVotes == c ? 0 : 1))) << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}