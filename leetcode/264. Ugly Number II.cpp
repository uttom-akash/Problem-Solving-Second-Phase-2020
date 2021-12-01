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
    int nthUglyNumber(int n)
    {
        set<int> unums;
        unums.insert(1);
        int ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans = *(unums.begin());
            unums.erase(ans);

            unums.insert(2 * ans);
            unums.insert(3 * ans);
            unums.insert(5 * ans);
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