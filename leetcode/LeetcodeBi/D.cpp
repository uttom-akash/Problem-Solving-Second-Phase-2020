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

struct p
{
    int index;
    int soc;

    bool operator<(const p &a)
    {
        return soc < a.soc;
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        int n;
        cin >> n;
        p a[n + 5];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i].soc;
            a[i].index = i + 1;
        }

        sort(a, a + n);

        vector<pair<int, int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[n - 1].soc == 0)
                break;

            while (a[i].soc > 0)
            {
                a[i].soc--;
                int index = lower_bound(a, a + n, a[n - 1]) - a;

                if (i >= index)
                    break;
                ans.push_back({a[i].index, a[index].index});
                a[index].soc--;
            }
        }

        cout << ans.size() << "\n";
        for (auto p : ans)
        {
            cout << p.first << " " << p.second << "\n";
        }
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}