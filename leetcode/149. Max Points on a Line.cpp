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
    pair<int, int> getSlope(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first == p2.first && p1.second == p2.second)
        {
            return {INT_MAX, INT_MAX};
        }
        else if (p1.first == p2.first)
        {
            return {INT_MAX, 0};
        }
        else if (p1.second == p2.second)
        {
            return {0, 0};
        }
        else
        {
            int gc = __gcd(p1.second - p2.second, p1.first - p2.first);

            auto slope = make_pair((p1.second - p2.second) / gc, (p1.first - p2.first) / gc);

            if (slope.first < 0)
            {
                slope.first = -slope.first;
                slope.second = -slope.second;
            }
            return slope;
        }
    }

    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 1;
        map<pair<int, int>, int> mapper;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int duplicates = 0;
            for (int j = i + 1; j < n; j++)
            {
                auto slope = getSlope({points[i][0], points[i][1]}, {points[j][0], points[j][1]});

                cout << slope.first << " " << slope.second << "\n";

                if (slope.first == INT_MAX && slope.second == INT_MAX)
                {
                    duplicates++;
                    continue;
                }

                mapper[slope]++;
                cnt = max(mapper[slope], cnt);
            }
            cout << "\n";
            ans = max(ans, cnt + duplicates);
        }

        return ans;
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