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
    int countNumbersWithUniqueDigits(int n)
    {
        int dp[10];

        dp[0] = 1;
        dp[1] = 10;

        for (int i = 2; i <= n; i++)
        {
            int option = 9;             // we won't put 0 at first place , so there are 9 options from 1 to 9
            int noZeroAtFirst = option; //  choosing 1st position digits

            for (int j = 2; j <= i; j++) // already placed 1st position digits so starting from 2
            {
                noZeroAtFirst *= option--;
            }

            dp[i] = noZeroAtFirst + dp[i - 1]; // if we put 0 at 1st position , then there will be ans for previous n-1
        }

        return dp[n];
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