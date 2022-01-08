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

        string s, t, ss = "";
        cin >> s >> t;

        int n = s.size();
        sort(s.begin(), s.end());

        if (t == "abc" and s.find('c') != n)
        {
            string c = "";
            int aep = 0;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'c')
                    c += 'c';
                else
                    ss += s[i];

                if (s[i] == 'a')
                    aep++;
            }

            ss = ss.substr(0, aep) + c + ss.substr(aep, ss.size());
        }
        else
        {
            ss = s;
        }

        cout << ss << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}