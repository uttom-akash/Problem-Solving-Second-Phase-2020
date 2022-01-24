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

    int n,k,a;
    cin >> n>>k>>a;

    int person= (k+a-1)%n;

    if(person==0)person=n;

    cout << person<< "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}