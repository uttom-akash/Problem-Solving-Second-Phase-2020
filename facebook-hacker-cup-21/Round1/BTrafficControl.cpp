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

void setupFileIO(string fin = "data/traffic_control_input.txt", string fout = "data/Boutput.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int N, M, A, B;
        cin >> N >> M >> A >> B;

        int shortPath = N + M - 1;

        if (shortPath > A || shortPath > B)
        {
            cout << "Case #" << tc << ": Impossible\n";
            continue;
        }

        int A1 = A - (shortPath - 1);
        int B1 = B - (shortPath - 1);

        int grid[N + 5][M + 5];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                grid[i][j] = 1000;
        }

        int r1 = 0, c1 = 0, r2 = N - 1, c2 = 0;
        for (int i = 0; i < shortPath; i++)
        {
            grid[r1][c1] = 1;
            grid[r2][c2] = 1;

            if (c1 < M - 1)
                c1++;
            else
                r1++;

            if (c2 < M - 1)
                c2++;
            else
                r2--;
        }

        grid[0][0] = A1;
        grid[N - 1][0] = B1;

        cout << "Case #" << tc << ": Possible\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << grid[i][j];
                if (j != M - 1)
                    cout << " ";
            }
            cout << "\n";
        }
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}