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

class Solution
{
public:
    int numSquares(int n)
    {
        int sums[n + 5];
        fill_n(&sums[0], n + 5, INT_MAX);

        sums[0] = 0;

        for (int sum = 1; sum <= n; sum++)
        {
            for (int sq = 1; sq * sq <= sum; sq++)
            {
                sums[sum] = min(sums[sum], sums[sum - sq * sq] + 1);
            }
        }

        return sums[n];
    }
};

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