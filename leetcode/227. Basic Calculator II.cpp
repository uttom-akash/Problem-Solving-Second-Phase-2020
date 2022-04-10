#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int sz = s.size();
        int res = 0, prev = 0, curr = 0;
        char prevSign = '+';

        for (int i = 0; i < sz; i++)
        {
            if ('0' <= s[i] and s[i] <= '9')
            {
                curr = curr * 10 + (s[i] - '0');
            }
            if ((s[i] != ' ' and s[i] < '0' || '9' < s[i]) || i == sz - 1)
            {
                switch (prevSign)
                {
                case '+':
                    res += prev;
                    prev = curr;
                    break;
                case '-':
                    res += prev;
                    prev = -curr;
                    break;
                case '*':
                    prev *= curr;
                    break;
                case '/':
                    prev /= curr;
                    break;
                }

                prevSign = s[i];
                curr = 0;
            }
        }

        res += prev;
        return res;
    }
};