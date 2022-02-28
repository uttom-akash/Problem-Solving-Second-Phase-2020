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


int getMinD(char a, char b){
    int posa=a-'a';
    int posb=b-'a';

    return min(abs(posa-posb),min((26-posa+posb),(26-posb+posa)));
}

void solve()
{

    int ntc ;
    cin>>ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        string s,f;
        cin>>s>>f;

        int szs=s.size(),szf=f.size();
        int ans =0;
        for (int i = 0; i < szs; i++)
        {
            int minD=INT_MAX;
            for (int j = 0; j < szf; j++)
            {
                minD=min(minD,getMinD(s[i],f[j]));
            }
            ans+=minD;
        }
        
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }    
}

int main()
{
    optimize();

    solve();

    return 0;
}