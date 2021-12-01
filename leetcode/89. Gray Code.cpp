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
    vector<int> grayCode(int n)
    {
        vector<int> grayCodes;
        grayCodes.push_back(0);
        grayCodes.push_back(1);

        for (int bit = 1; bit < n; bit++)
        {
            auto prevListSz = grayCodes.size();
            for (int ri = prevListSz - 1; ri >= 0; ri--)
            {
                grayCodes.push_back(1 << bit | grayCodes[ri]);
            }
        }

        return grayCodes;
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