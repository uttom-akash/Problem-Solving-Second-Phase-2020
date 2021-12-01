#include <bits/stdc++.h>

#define mx 10000000
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
        int x1, p1, x2, p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;

        double xx1 = x1, xx2 = x2;
        while (xx1 > 1)
        {
            xx1 /= 10.0;
            p1++;
        }

        while (xx2 > 1)
        {
            xx2 /= 10.0;
            p2++;
        }

        if (p1 < p2)
        {
            cout << "<\n";
        }
        else if (p1 > p2)
        {
            cout << ">\n";
        }
        else if (xx1 < xx2)
        {
            cout << "<\n";
        }
        else if (xx1 > xx2)
        {
            cout << ">\n";
        }
        else
            cout << "=\n";
        // {
        //     //  cout << x1 << " " << x2 << "\n";
        //     while (x1 < mx and p1--)
        //     {
        //         x1 *= 10;
        //     }
        //     while (x2 < mx and p2--)
        //     {
        //         x2 *= 10;
        //     }

        //     //cout << x1 << " " << x2 << "\n";
        //     if (x1 < x2)
        //     {
        //         cout << "<\n";
        //     }
        //     else if (x1 > x2)
        //     {
        //         cout << ">\n";
        //     }
        //     else
        //         cout << "=\n";
        // }
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}