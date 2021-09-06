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
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, mxSum = 0, mxNum = -100000;

        for (int num : nums)
        {
            mxNum = max(mxNum, num);
            sum = max(sum + num, 0);
            mxSum = max(mxSum, sum);
        }

        if (mxNum < 0)
            mxSum = mxNum;

        return mxSum;
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