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
    int minMoves(int target, int maxDoubles) {

        int ans=0;
        while (maxDoubles && target>1)
        {
            if(target&1)target--;
            else {
                target>>=1;
                maxDoubles--;
            }
            ans++;
        }

        ans+=(--target);

        return ans;
           
    }
};

void solve()
{

    Solution s;
    s.minMoves(19,2);
}

int main()
{
    optimize();

    solve();

    return 0;
}