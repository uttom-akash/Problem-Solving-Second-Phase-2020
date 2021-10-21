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

    for (int tc = 0; tc < ntc; tc++)
    {
        int n,h;
        cin>>n>>h;

        int mxa1=0,mxa2=0;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;

            if(a>mxa1){
                mxa2=mxa1;
                mxa1=a;
            }
            else if(a>mxa2){
                mxa2=a;
            }
        }

        int ans = (h/(mxa1+mxa2))*2;
        h%=(mxa1+mxa2);
        if(h>mxa1)
            ans+=2;
        if(h>0 && h<=mxa1)
            ans++;
        
        cout << ans << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}