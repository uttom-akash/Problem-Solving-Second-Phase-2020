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
    int maxProduct(vector<int> &nums)
    {
        int minProd = 1, maxProd = 1;
        int ans = INT_MIN;

        for (auto num : nums)
        {
            if (num < 0)
            {
                swap(minProd, maxProd);
            }

            maxProd = max(maxProd * num, num);
            minProd = min(minProd * num, num);
            ans = max(ans, maxProd);
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