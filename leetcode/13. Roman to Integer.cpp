#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{

private:
    short getShort(char c)
    {
        return (c - 'A');
    }

public:
    int romanToInt(string s)
    {
        short romArr[30] = {0};
        romArr[getShort('I')] = 1;
        romArr[getShort('V')] = 5;
        romArr[getShort('X')] = 10;
        romArr[getShort('L')] = 50;
        romArr[getShort('C')] = 100;
        romArr[getShort('D')] = 500;
        romArr[getShort('M')] = 1000;

        int sz = s.size(), ans = 0;
        for (int i = 0; i < sz; i++)
        {
            auto curr = romArr[getShort(s[i])];

            if (i + 1 < sz && curr < romArr[getShort(s[i + 1])])
            {
                ans += (romArr[getShort(s[i + 1])] - curr);
                i++;
                continue;
            }

            ans += curr;
        }

        return ans;
    }
};