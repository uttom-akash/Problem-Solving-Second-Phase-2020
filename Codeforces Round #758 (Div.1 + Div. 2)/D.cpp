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

int findMaxGCD(int arr[], int n, int even)
{
    int high = 0;
    for (int i = 0; i < n; i++)
        high = max(high, arr[i]);

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    int divisors[high + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j * j <= abs(arr[i]); j++)
        {
            if (arr[i] % j == 0)
            {
                divisors[j]++;
                if (j != arr[i] / j)
                    divisors[arr[i] / j]++;
            }
        }
    }

    int ans = 0;
    for (int i = high; i >= 1; i--)
        if (divisors[i] == even)
            ans = max(ans, i);

    return ans;
}

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        int n;
        cin >> n;

        int a[n + 5];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = findMaxGCD(a, n, n / 2);
        if (ans >= 1)
            cout
                << ans << "\n";
        else
            cout << "-1\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}