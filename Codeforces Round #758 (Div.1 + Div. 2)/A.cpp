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
        int n;
        cin >> n;

        int prev = 2, curr = 3, i = 1;
        cout << prev;
        while (i < n)
        {
            if (curr % prev != 0)
            {
                cout << " " << curr;
                prev = curr;
                i++;
            }

            curr++;
        }
        cout << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}