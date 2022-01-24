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
        int n, a, b;
        cin >> n >> a >> b;

        int mid = n - 2;
        int half = ceil(mid / 2.0);

        if (mid < a + b)
        {
            cout << -1 << "\n";
            continue;
        }
        else if (half < a || half < b)
        {
            cout << -1 << "\n";
            continue;
        }
        else if (abs(a - b) > 1)
        {
            cout << -1 << "\n";
            continue;
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(i);
        }

        int si = a < b ? 0 : 1;
        int done = max(a, b);

        if (a <= b)
        {
            for (; si < n - 2 && done > 0; si += 2, done--)
            {
                swap(ans[si], ans[si + 1]);
            }
        }
        else
        {
            si = n - 2;
            for (; si > 0 && done > 0; si -= 2, done--)
            {
                swap(ans[si], ans[si + 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
            if (i == n - 1)
            {
                cout << "\n";
            }
            else
            {
                cout << " ";
            }
        }
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}