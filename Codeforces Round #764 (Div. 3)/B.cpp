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
        int a, b, c;
        cin >> a >> b >> c;

        int first = b + b - c;
        int second = a + c;
        int third = b + b - a;

        // cout<<first<<" "<<second<<" "<<third<<"\n";
        if(second%2==0 && (second/2)>0 && (second/2)%b==0)
        {
            cout<<"YES\n";
        }
        else if (first>0 && first % a == 0)
        {
            cout<<"YES\n";
        }
        else if (third>0 && third % c == 0)
        {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}