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

int getSteps(ll n, ll a, ll b)
{
    int posA = -1, posB = -1, i = 0;
    while (n > 0)
    {
        ll digit = n % 10;
        n /= 10;
        if (digit == a && posA < 0)
        {
            posA = i;
        }

        if (digit == b && posB < 0)
        {
            posB = i;

            if (posA <= posB)
                posA = -1;
        }

        i++;
    }

    // cout << "OK__" << posA << " " << posB << "\n";
    if (posB < 0 || posA < 0)
        return INT_MAX;
    else
        return (posA - posB - 1) + posB;
}

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        ll n;
        cin >> n;

        int ans = INT_MAX;
        ans = min(ans, getSteps(n, 0, 0));
        ans = min(ans, getSteps(n, 2, 5));
        ans = min(ans, getSteps(n, 5, 0));
        ans = min(ans, getSteps(n, 7, 5));
        cout << ans << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}