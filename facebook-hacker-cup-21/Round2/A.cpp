#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "data/input.txt", string fout = "data/Aoutput.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

int getIndex(int a[], int used[], int key, int n)
{
    int lo = 0, hi = n - 1;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int value = a[mid];
        int isUsed = used[mid];
        if (value == key)
        {
            if (isUsed)
                lo++;
            else
                return mid;
        }
        else if (value > key)
            hi = mid;
        else
            lo = mid + 1;
    }

    return lo;
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int n, m;
        cin >> n >> m;

        int models[100 + 5], mChange[100 + 5][100 + 5], rounds[100][100], used[100][100];

        for (size_t i = 0; i < m; i++)
        {
            cin >> models[i];
        }

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                cin >> rounds[i][j];
                used[i][j] = 0;
                mChange[i][j] = 0;
            }

            sort(rounds[i], rounds[i] + m);
        }

        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            stack<int> keeps;
            for (size_t j = 0; j < m; j++)
            {
                keeps.push(j);
                int index = getIndex(rounds[i], used[i], models[j], m);
                if (rounds[i][index] != models[j] || used[index])
                {
                    mChange[i + 1][j] = 1;
                }
                else
                {

                    models[j] = rounds[i][index];
                    used[i][index] = 1;
                }
            }
            for (size_t j = 0; j < m; j++)
            {
                if (mChange[i + 1][j])
                {
                    int index = getIndex(rounds[i], used[i], models[j], m);
                    models[j] = rounds[i][index];
                    used[i][index] = 1;
                }

                mChange[i + 1][j] += mChange[i][j];
            }
        }

        for (size_t j = 0; j < n; j++)
        {
            ans += max(mChange[n][j] - 1, 0);
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}