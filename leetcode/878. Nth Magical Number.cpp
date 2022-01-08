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
    int nthMagicalNumber(int n, int a, int b)
    {
        long lo = 2, hi = 4LL * 1e14;
        long lcm = a * b / __gcd(a, b);
        long modulo = 1e9 + 7;

        while (lo < hi)
        {
            long mid = (hi + lo) >> 1;
            long nMagicNums = mid / a + mid / b - mid / lcm;

            if (nMagicNums >= n)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return static_cast<int>(lo % modulo);
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