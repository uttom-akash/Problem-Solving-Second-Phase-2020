

#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long
#define way4                               \
    (int[4][2])                            \
    {                                      \
        {0, 1}, {1, 0}, {0, -1}, { -1, 0 } \
    }

#define way8                                                                   \
    (int[8][2])                                                                \
    {                                                                          \
        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, { -1, 1 } \
    }

//fill_n(&a[0][0], ntc * ntc, -100);

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
        string s;
        cin >> s;
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}