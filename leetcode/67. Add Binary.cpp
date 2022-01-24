#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int carry = 0;

        int sz = max(a.size(), b.size());

        a = fillFull(a, sz);
        b = fillFull(b, sz);

        for (int i = sz - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 2;
            sum = sum % 2;

            ans = (char)(sum + '0') + ans;
        }

        return ans;
    }

    string fillFull(string a, int sz)
    {
        int l = a.size();
        for (int i = l; i < sz; i++)
        {
            a = "0" + a;
        }

        return a;
    }
};