#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

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
        int minProd = 1, maxProd = 1, bestMax = INT_MIN;
        int cnt = nums.size();

        for (int i = 0; i < cnt; i++)
        {
            if (nums[i] < 0)
            {
                int t = minProd;
                minProd = maxProd;
                maxProd = t;
            }

            minProd = min(minProd * nums[i], nums[i]);
            maxProd = max(maxProd * nums[i], nums[i]);

            bestMax = max(bestMax, maxProd);
        }

        return bestMax;
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