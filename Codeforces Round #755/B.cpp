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

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int n,m;
        cin >> n>>m;

        int ans=0;
        if(n%3==0){
            ans=m*(n/3);
        }else if(m%3==0){
            ans=n*(m/3);
        }else{
            n=min(n,m);
            m=max(n,m);

            ans=n*(m/3);
            ans+=(m%3)*(n/3);
            ans+=(n%3);
        }

        cout <<  ans << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}