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
        char l = '(', r = ')';
        int rec = 0;

        for (int i = 0; i < n; i++)
        {
            string seq = "";
            for (int j = 0; j < n; j++)
            {
                seq += "()";
                while (j < i)
                {
                    seq = '(' + seq + ')';
                    j++;
                }
            }
            cout << seq << "\n";
        }
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}