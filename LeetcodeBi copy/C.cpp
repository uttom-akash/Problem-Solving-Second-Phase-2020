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
    long long mostPoints(vector<vector<int>>& questions) {
        int sz= questions.size();
        long long dp[sz+5][2];

        dp[sz][0]=0;
        dp[sz][1]=0;
        
        long long ans=0;
        
        for (int i = sz-1; i >=0; i--)
        {
            int p=questions[i][0];
            int skip=questions[i][1]+1;

            dp[i][0]=p;
            if(i+skip<sz){
                dp[i][0]+= max(dp[i+skip][0],dp[i+skip][1]);
            }

            dp[i][1]= max(dp[i+1][0],dp[i+1][1]);
            
            
            ans= max(dp[i][0],dp[i][1]);
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