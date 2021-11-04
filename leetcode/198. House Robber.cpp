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
    int rob(vector<int> &nums)
    {
        int sz = nums.size();
        int money[4][sz + 5];
        int ans = 0;

        memset(money, 0, sizeof(money));

        for (int i = 1; i <= sz; i++)
        {
            int amnt = nums[i - 1];
            money[0][i] = max(money[0][i - 1], money[1][i - 1]);
            if (i == 2)
                money[2][i] = money[2][i - 1];
            else
                money[2][i] = max(money[2][i - 1], money[1][i - 1]);

            money[1][i] = money[0][i - 1] + amnt;
            ans = max(money[0][i], money[1][i]);
        }

        return ans;
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