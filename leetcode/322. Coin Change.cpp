#include <bits/stdc++.h>

#define mx 10001
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
    int coinChange(vector<int> &coins, int amount)
    {
        int amounts[amount + 5];
        int n = coins.size();

        for (int amnt = 1; amnt <= amount; amnt++)
        {
            amounts[amnt] = mx;
        }
        amounts[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int amnt = 1; amnt <= amount; amnt++)
            {
                if (amnt - coins[i] >= 0)
                {
                    amounts[amnt] = min(amounts[amnt], amounts[amnt - coins[i]] + 1);
                }
            }
        }

        return amounts[amount] == mx ? -1 : amounts[amount];
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