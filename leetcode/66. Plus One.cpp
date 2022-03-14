#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int sz = digits.size();
        reverse(digits, sz);

        int carry = 1;

        for (int i = 0; i < sz; i++)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }

        if (carry)
        {
            digits.push_back(carry);
            sz++;
        }
        reverse(digits, sz);

        return digits;
    }

    void reverse(vector<int> &digits, int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            swap(digits[i], digits[n - i - 1]);
        }
    }
};