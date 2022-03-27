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
    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        int halfL = ceil(intLength / 2.00);
        long long init = 1, ub = 1;

        for (int i = 0; i < halfL-1; i++)
        {
            init = init * 10;
        }

        ub = init * 10;

        // cout<<init<<" "<<ub<<"\n";
        
        vector<long long> ans;

        for (auto q : queries)
        {

            if (init + q - 1 < ub)
                ans.push_back(init + q - 1);
            else
                ans.push_back(-1);
        }

        int sz=queries.size();
        for (int i = 0; i < sz; i++)
        {
            if(ans[i]==-1)
                continue;
            ans[i]=makePalindrome(ans[i],(intLength%2));
        }

        return ans;
    }

    long long makePalindrome(long long num, bool odd)
    {
        long long pal = num;
        
        if (odd)
            num /= 10;
        while (num)
        {
            pal = pal * 10 + num % 10;
            num /= 10;
        }

        return pal;
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