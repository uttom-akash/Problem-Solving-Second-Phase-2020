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

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int sz = s.size();
        vector<string> ans;
        for (int i = 0; i < sz; i+=k)
        {
            auto ss=s.substr(i,k);
            while (ss.size()<k)
            {
                ss=ss+fill;
            }
            ans.push_back(ss);
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
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}