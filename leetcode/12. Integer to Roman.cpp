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
    vector<pair<string, int>> v;

public:
    Solution()
    {
        v.push_back({"I", 1});
        v.push_back({"IV", 4});
        v.push_back({"V", 5});
        v.push_back({"IX", 9});
        v.push_back({"X", 10});
        v.push_back({"XL", 40});
        v.push_back({"L", 50});
        v.push_back({"XC", 90});
        v.push_back({"C", 100});
        v.push_back({"CD", 400});
        v.push_back({"D", 500});
        v.push_back({"CM", 900});
        v.push_back({"M", 1000});
    }

    string intToRoman(int num)
    {
        string ans = "";
        reverse(v.begin(), v.end());

        for (auto e : v)
        {
            string csym = e.first;
            int vsym = e.second;

            while (vsym <= num)
            {
                num = num - vsym;
                ans = ans + csym;
            }
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