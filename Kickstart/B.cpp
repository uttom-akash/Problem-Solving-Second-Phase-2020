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

struct furn
{
    int x0, y0, x1, y1;

    int getMinDist(furn other)
    {
        return getMinDistX(other) + getMinDistY(other);
    }

    int getMinDistC(pair<int, int> p)
    {
        int distX = INT_MAX;
        if (x0 <= p.first && p.first <= x1)
            distX = 0;

        distX = min(distX, abs(x0 - p.first));
        distX = min(distX, abs(x1 - p.first));

        int distY = INT_MAX;
        if (y0 <= p.second && p.second <= y1)
            distY = 0;

        distY = min(distY, abs(y0 - p.second));
        distY = min(distY, abs(y1 - p.second));

        return distX + distY;
    }

    int getMinDistX(furn other)
    {
        int distX = INT_MAX;
        if (!(x1 < other.x0 || other.x1 < x0))
            distX = 0;

        distX = min(distX, abs(x0 - other.x0));
        distX = min(distX, abs(x0 - other.x1));

        distX = min(distX, abs(x1 - other.x0));
        distX = min(distX, abs(x1 - other.x1));
    }

    int getMinDistY(furn other)
    {
        int distY = INT_MAX;
        if (!(y1 < other.y0 || other.y1 < y0))
            distY = 0;

        distY = min(distY, abs(y0 - other.y0));
        distY = min(distY, abs(y0 - other.y1));

        distY = min(distY, abs(y1 - other.y0));
        distY = min(distY, abs(y1 - other.y1));
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int k;
        cin >> k;

        furn furnitures[k + 5];
        for (int i = 0; i < k; i++)
        {
            cin >> furnitures[i].x0 >> furnitures[i].y0 >> furnitures[i].x1 >> furnitures[i].y1;
        }

        int ans = INT_MAX, ax, ay;
        for (int i = -100; i <= 100; i++)
        {
            for (int j = -100; j <= 100; j++)
            {
                int ansI = 0;
                for (int l = 0; l < k; l++)
                {
                    ansI += furnitures[l].getMinDistC({i, j});
                }

                if (ansI < ans)
                {
                    ans = ansI;
                    ax = i, ay = j;
                }
            }
        }

        cout << "Case #" << tc << ": " << ax << " " << ay << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}