#include <bits/stdc++.h>

#define mx 1000000000
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
        int n,k;
        cin>>n>>k;

        int a[5],ca[5];

        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            ca[i]=a[i];
        }

        sort(ca,ca+n);

        bool ans =true;
        for (int i = 0; i < n; i++)
        {
            int index = lower_bound(ca,ca+n,a[i])-ca;
            ca[index]-=mx;
            if(abs(index-i)==0) continue;

            if(abs(index-i)>=k) continue;

            if((i+k<n && abs(index-i-k)>=k) || (i+2*k<n && abs(index-i-2*k)>=k)) continue;

            if((i-k>=0 && abs(index-i+k)>=k) || (i-2*k>=0 && abs(index-i+2*k)>=k)) continue;

            ans=false;
            break;
        }
        
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}