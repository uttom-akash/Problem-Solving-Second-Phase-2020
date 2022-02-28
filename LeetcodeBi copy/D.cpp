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
    long long maxRunTime(int n, vector<int> &batteries)
    {
        sort(batteries.begin(), batteries.end());
        int sz = batteries.size();
        int trck[sz + 5];
        memset(trck, 0, sizeof(trck));

        int red = 0;
        long long time = 0;

        for (int i = 0; i + n <= sz; i++)
        {
            int j = i + n;
            int charge = batteries[i] - red;

            if (charge > 1)
            {
                time += (charge - 1);
                trck[i] -= (charge - 1);
                trck[j] += (charge - 1);
            }

            red += trck[i];
        }

        red = 0;
        for (int i = 0; i < sz; i++)
        {
            red += trck[i];
            batteries[i] += red;
        }

        stack<int> st;
        red = 0;
        for (size_t i = sz - 1; i >= 0; i--)
        {
            if (batteries[i] > 0)
            {
                st.push(batteries[i]);
                if (st.size() == n)
                {
                    int tp = st.top();
                    
                }
            }
        }
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}