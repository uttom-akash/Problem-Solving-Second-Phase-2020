#include <bits/stdc++.h>

#define limit 10000
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base ::sync_with_stdio(false);
}

void setupFileIO(string fin = "data/xs_and_os_input.txt", string fout = "data/Boutput.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

pair<int, int> checkRow(string row, int n)
{
    int nX = 0;
    int pos;
    for (int i = 0; i < n; i++)
    {
        if (row[i] == 'O')
            return {INT_MAX, pos};
        if (row[i] == '.')
            nX++, pos = i;
    }
    return {nX, pos};
}

string colToRow(string grid[], int col, int n)
{

    string row = "";
    for (int i = 0; i < n; i++)
    {
        row += grid[i][col];
    }
    return row;
}

pair<int, int> canWin()
{
    int n;
    cin >> n;
    string grid[n + 5];
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int xNeeded = INT_MAX;
    int nSet = 0;
    for (int i = 0; i < n; i++)
    {
        int nxr = checkRow(grid[i], n).first;
        int nxc = checkRow(colToRow(grid, i, n), n).first;
        xNeeded = min(xNeeded, min(nxr, nxc));
    }

    if (xNeeded == INT_MAX)
        return {xNeeded, nSet};

    int mapper[n + 5];
    memset(mapper, 0, sizeof(mapper));

    for (int ri = 0; ri < n; ri++)
    {
        auto res = checkRow(grid[ri], n);
        if (res.first == xNeeded)
        {
            nSet++;
            mapper[res.second] = 1;
        }
    }

    for (int ci = 0; ci < n; ci++)
    {
        auto res = checkRow(colToRow(grid, ci, n), n);
        if (mapper[ci] && xNeeded == 1)
            continue;
        if (res.first == xNeeded)
        {
            nSet++;
        }
    }

    return {xNeeded, nSet};
}

void solve()
{
    int ntc;

    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        auto res = canWin();
        if (res.first == INT_MAX)
            cout << "Case #" << tc << ": "
                 << "Impossible\n";
        else
            cout << "Case #" << tc << ": " << res.first << " " << res.second << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}