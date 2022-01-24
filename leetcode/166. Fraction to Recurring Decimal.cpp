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
    string fractionToDecimal(int numerator, int denominator)
    {
        string ans = to_string(numerator / denominator);
        numerator %= denominator;

        unordered_map<int, int> mapper;

        if (numerator)
        {
            ans += ".";
            numerator *= 10;

            bool notDividedYet = true;

            while (numerator)
            {
                if (mapper[numerator])
                {
                    ans.insert(mapper[numerator], "(");
                    ans += ')';
                    break;
                }

                if (numerator >= denominator)
                {
                    notDividedYet = false;
                    mapper[numerator] = ans.size();
                    ans += to_string(numerator / denominator);
                    numerator %= denominator;
                }
                else
                {
                    numerator *= 10;

                    if (notDividedYet)
                    {
                        ans += "0";
                    }
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