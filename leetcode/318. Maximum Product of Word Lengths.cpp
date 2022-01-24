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
    int maxProduct(vector<string> &words)
    {
        int sz = words.size();

        vector<bitset<26>> wordMapper;

        for (int i = 0; i < sz; i++)
        {
            bitset<26> bits;
            for (int j = 0; j < words[i].size(); j++)
            {
                bits.set(words[i][j] - 'a', 1);
            }
            wordMapper.push_back(bits);
        }

        int ans = 0;
        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                auto isCommon = wordMapper[i] & wordMapper[j];
                if (isCommon.none())
                {
                    int prod = words[i].size() * words[j].size();
                    ans = max(ans, prod);
                }
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