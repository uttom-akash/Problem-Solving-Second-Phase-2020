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
        int n, m, k;
        cin >> n >> m >> k;
        string s[n];
        int ok[n + 5][m + 5];
        memset(ok, 0, sizeof(ok));

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '*')
                {
                    int ci = i, cj = j, h = 0;
                    while (ci >= 0 && cj - h >= 0 && cj + h < m && s[ci][cj - h] == '*' && s[ci][cj + h] == '*')
                    {
                        ci--;
                        h++;
                    }

                    h--;
                    if (k > h)
                    {
                        continue;
                    }

                    ci = i, cj = j, h = 0;
                    while (ci >= 0 && cj - h >= 0 && cj + h < m && s[ci][cj - h] == '*' && s[ci][cj + h] == '*')
                    {
                        ok[ci][cj - h] = 1;
                        ok[ci][cj + h] = 1;
                        ci--;
                        h++;
                    }
                }
            }
        }

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == '*' && ok[i][j] == 0)
                {
                    ans = false;
                    break;
                }
            }
            if (ans == false)
                break;
        }
        if (ans == false)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}