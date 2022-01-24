
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

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> uglies;

        int nxtMultiplier[1005];
        int ugliesList[n + 5];

        int sz = primes.size();

        ugliesList[0] = 1;

        for (auto p : primes)
        {
            uglies.push({p, p});
            nxtMultiplier[p] = 1;
        }

        for (int i = 1; i < n;)
        {
            auto cUgly = uglies.top();

            uglies.pop();

            if (ugliesList[i - 1] != cUgly.first)
            {
                ugliesList[i++] = cUgly.first;
            }

            if (INT_MAX / cUgly.second > ugliesList[nxtMultiplier[cUgly.second]])
            {
                int ug = ugliesList[nxtMultiplier[cUgly.second]] * cUgly.second;

                uglies.push({ug, cUgly.second});

                nxtMultiplier[cUgly.second]++;
            }
        }
        return ugliesList[n - 1];
    }
};
void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        string s;
        cin >> s;
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}