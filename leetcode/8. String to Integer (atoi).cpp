#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        long result = 0;
        long neg = 1;

        int i = 0, sz = s.size();

        while (i < sz and s[i] == ' ')
            i++;

        if (i < sz and (s[i] == '-' || s[i] == '+'))
        {
            neg = s[i] == '-' ? -1 : 1;
            i++;
        }

        while (i < sz and ('0' <= s[i] and s[i] <= '9'))
        {
            char c=s[i];
            result = result * 10 + (int)(c - '0');
            i++;

            result = result > INT_MAX ? INT_MAX : result;
            result = neg * result < INT_MIN ? neg * INT_MIN : result;
        }
        
        return neg * result;
    }
};