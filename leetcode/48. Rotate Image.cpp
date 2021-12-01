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
private:
    int x, y, lo, hi;
    int dx, dy;

public:
    Solution()
    {
        dx = 1, dy = 0;
    }

    void nextDirection()
    {
        if (x + dx > hi)
            dx = 0, dy = 1;
        else if (x + dx < lo)
            dx = 0, dy = -1;
        else if (y + dy > hi)
            dx = -1, dy = 0;
        else if (y + dy < lo)
            dx = 1, dy = 0;
    }

    void next()
    {
        nextDirection();
        x += dx, y += dy;
    }

    void rotate(vector<vector<int>> &matrix)
    {
        lo = 0, hi = matrix[0].size() - 1;
        int penetrate = 0;
        while (lo < hi)
        {
            int rot = hi - lo;
            while (rot--)
            {
                x = y = penetrate;
                auto tmp = matrix[y][x];
                while (true)
                {
                    next();
                    swap(tmp, matrix[y][x]);
                    if (x == penetrate and y == penetrate)
                        break;
                }
            }
            penetrate++;
            lo++, hi--;
        }
    }
};

void solve()
{

    Solution s;
    vector<vector<int>> v({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    s.rotate(v);
}

int main()
{
    optimize();

    solve();

    return 0;
}