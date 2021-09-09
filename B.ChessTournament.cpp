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
        cin >> n;
        string s, mat[n + 5];
        int mapper[n + 5];
        memset(mapper, -1, sizeof(mapper));
        cin >> s;

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            mat[i] = "";
            if (s[i] == '1')
            {
                for (int j = 0; j < n; j++)
                {
                    mat[i] += i == j ? 'X' : '=';
                }
            }
            else
            {
                bool couldnt = true;
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        mat[i] += "X";
                    }
                    else if (s[j] == '1')
                        mat[i] += '=';
                    else if (mapper[i] == -1 && mapper[j] != i)
                    {
                        mat[i] += '+';
                        mapper[i] = j;
                        couldnt = false;
                    }
                    else
                    {
                        mat[i] += '-';
                    }
                }

                if (couldnt)
                {
                    cout << "NO\n";
                    possible = false;
                    break;
                }
            }
        }

        if (possible)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                cout << mat[i] << "\n";
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