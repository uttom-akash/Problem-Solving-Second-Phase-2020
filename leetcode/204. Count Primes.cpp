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
    int countPrimes(int n)
    {
        bitset<2500001> primes;

        for (int i = 3; i * i < n; i += 2)
        {
            if (!primes[i >> 1])
            {
                for (int j = i * i; j < n; j += 2 * i)
                {
                    primes.set(j >> 1);
                }
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (i == 2 || (i & 1 && !primes[i >> 1]))
            {
                ans++;
            }
        }

        return ans;
    }
};

void solve()
{

    Solution s;
    s.countPrimes(50);
}

int main()
{
    optimize();

    solve();

    return 0;
}