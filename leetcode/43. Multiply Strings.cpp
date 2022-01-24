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
    string add(string a, string b)
    {
        int l = max(a.size(), b.size());
        int carry = 0;
        string ans = "";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (size_t i = 0; i < l; i++)
        {
            int ms = 0;
            ms = ms + (i < a.size() ? a[i] - '0' : 0);
            ms = ms + (i < b.size() ? b[i] - '0' : 0);
            ms += carry;

            carry = ms / 10;
            ms = ms % 10;
            ans = ans + (char)(ms + '0');
        }
        if (carry > 0)
            ans = ans + (char)(carry + '0');

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string mult(string a, string b)
    {
        int sza = a.size();
        int szb = b.size();
        int carry = 0;
        string ans = "";
        string zeros = "";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (size_t i = 0; i < szb; i++)
        {
            string mans = "";
            for (size_t j = 0; j < sza; j++)
            {

                int mm = (a[j] - '0') * (b[i] - '0') + carry;
                carry = mm / 10;
                mans += (char)((mm % 10) + '0');
            }
            if (carry > 0)
                mans += (char)(carry + '0');

            carry = 0;
            reverse(mans.begin(), mans.end());
            ans = add(ans, mans + zeros);
            zeros += '0';
        }

        return ans;
    }

    string multiply(string num1, string num2)
    {
        auto s = mult(num1, num2);

        int i = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != '0')
                break;
        }

        if (i == s.size())
            return "0";
        else
            return s.substr(i);
    }
};

void solve()
{

    Solution s;
    cout << s.multiply("99999", "00") << "\n";
    cout << s.multiply("1000", "10") << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}