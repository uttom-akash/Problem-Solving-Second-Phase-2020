#include <bits/stdc++.h>

#define mx 10000

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

#define mod 1000000007
class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int prevS = 0;
        long long ans = 0, cnt = 0;

        for (auto c : corridor)
        {
            if (c == 'S')
            {
                prevS++;
                if (prevS == 3)
                {
                    ans = (ans * (cnt % mod)) % mod;
                    ans%=mod;
                    prevS = 1;
                }
            }
            else
            {
                if (prevS == 2)
                {
                    cnt++;
                }
            }
        }

        return ans;
    }
};

void solve()
{

    int n, k;
    cin >> n >> k;
    ll a[10 + 5], ch[10 + 5];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ch[i] = 0;
    }

    sort(a, a + n);

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            ch[i] += ch[i - 1];

        if (i + k - 1 < n)
        {
            ll take = a[i] - ch[i];
            if (take > 1)
            {
                take--;
                ans += take;
                ch[i] += take;
                ch[i + k] -= take;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i] -= ch[i];
    }

    sort(a, a + n);

    int lo = 0;
    while (lo < n && a[lo] == 0)
    {
        lo++;
    }

    ans += (n - lo) / k;

    cout << ans << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}