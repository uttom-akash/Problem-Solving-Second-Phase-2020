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
    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        int sz = rectangles.size();
        map<pair<int, int>, int> mapper;

        for (int i = 0; i < sz; i++)
        {

            int width = rectangles[i][0];
            int height = rectangles[i][1];
            int gcd = __gcd(width, height);
            width /= gcd;
            height /= gcd;

            cout << width << " " << height << "\n";
            mapper[{width, height}]++;
        }

        long long ans = 0;

        for (auto mp : mapper)
        {
            ans += (1LL * mp.second * (mp.second - 1) / 2);
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