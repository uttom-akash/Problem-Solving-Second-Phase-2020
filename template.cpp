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
    vector<int> v({1018586,
                   1024630,
                   1026844,
                   1027104,
                   1027968,
                   1031626,
                   1031994,
                   1033620,
                   1034745,
                   1036511,
                   1038096,
                   1038509,
                   1040552,
                   1040631,
                   1041088,
                   1041522,
                   1043114,
                   1043168,
                   1043425,
                   1043439,
                   1044159,
                   1045749,
                   1045882,
                   1046812,
                   1048382,
                   1018586,
                   1051273,
                   1052225,
                   1052813,
                   1053321,
                   1053633});
    map<int, bool> mapper;

    for (auto e : v)
    {
        if (mapper[e])
        {
            auto a = e;
            cout << e << "\n";
        }

        mapper[e] = true;
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}