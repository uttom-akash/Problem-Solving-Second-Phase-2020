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
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end(),greater<int>());

        int ans=0;
        for (size_t i = 0; i < n; i+=3)
        {
            ans+=cost[i];
            if(i+1<n)ans+=cost[i];
        }
        
        return ans;
    }
};

void solve()
{

   Solution s;
   s.checkAlmostEquivalent("abcdeef"
,"abaaacc");
}

int main()
{
    optimize();

    solve();

    return 0;
}