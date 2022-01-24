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

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int r = 1;

        for (int i = 1; i <= n; i++)
        {
            if (r < i)
                break;
            int maxJump = nums[i - 1];
            r = min(n, max(r, i + maxJump));
        }

        return r == n;
    }
};

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