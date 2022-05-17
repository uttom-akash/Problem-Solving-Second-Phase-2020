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

void applyManchers(string s)
{
    int n = s.size();
    string pS = "#";
    for (int i = 0; i < n; i++)
    {
        pS += s[i];
        pS += "#";
    }

    int N = pS.size(), center = 0, right = 0;
    int Z[N + 5];
    memset(Z, 0, sizeof Z);

    for (int i = 0; i < N; i++)
    {
        if (i < right)
            Z[i] = min(right - i, Z[2 * center - i]);

        while (i + Z[i] + 1 < N && i - Z[i] - 1 >= 0 && pS[i + Z[i] + 1] == pS[i - Z[i] - 1])
        {
            Z[i]++;
        }

        if (i + Z[i] > right)
        {
            center = i;
            right = i + Z[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i & 1)
            cout << pS[i] << " ";
        else
            cout << "# ";
    }
    cout << "\n";

    for (int i = 0; i < N + 1; i++)
    {
        cout << Z[i] << " ";
    }
}

void solve()
{
    string s = "xfxzannazdz";
    applyManchers(s);
}

int main()
{
    optimize();

    solve();

    return 0;
}