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

int needRed(char sq, bool *red)
{
    int need = false;
    if (sq == 'R' || sq == 'O' || sq == 'P' || sq == 'A')
        need = true;

    int change = need == false ? 0 : *red == true ? 0
                                                  : 1;
    *red = need;

    return change;
}

int needBlue(char sq, bool *blue)
{
    int need = false;
    if (sq == 'B' || sq == 'P' || sq == 'G' || sq == 'A')
        need = true;

    int change = need == false ? 0 : *blue == true ? 0
                                                   : 1;
    *blue = need;

    return change;
}

int needYel(char sq, bool *yel)
{
    int need = false;
    if (sq == 'Y' || sq == 'O' || sq == 'G' || sq == 'A')
        need = true;

    int change = need == false ? 0 : *yel == true ? 0
                                                  : 1;
    *yel = need;

    return change;
}

void unsetFlag(char sq, bool *red, bool *blue, bool *yel)
{
    if (!(sq == 'R' || sq == 'O' || sq == 'P' || sq == 'A'))
        *red = false;

    if (!(sq == 'B' || sq == 'P' || sq == 'G' || sq == 'A'))
        *blue = false;

    if (!(sq == 'Y' || sq == 'O' || sq == 'G' || sq == 'A'))
        *yel = false;
}

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool red = false, yel = false, blue = false;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += needRed(s[i], &red);
         //   cout<<ans<<" "<<red<<"\n";
            ans += needBlue(s[i], &blue);
           // cout<<ans<<" "<<blue<<"\n";
            ans += needYel(s[i], &yel);
            //cout<<ans<<" "<<yel<<"\n";

            unsetFlag(s[i], &red,&blue,&yel);
            //cout<<red<<" "<<blue<<" "<<yel<<"\n";
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}