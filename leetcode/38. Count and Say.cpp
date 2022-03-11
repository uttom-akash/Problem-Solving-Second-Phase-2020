#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        auto hear = countAndSay(n - 1);
        hear+="$";

        int sz = hear.size();
        string say = "";
        int cnt = 1;

        for (int i = 1; i < sz; i++)
        {
            if (hear[i - 1] == hear[i])
            {
                cnt++;
            }
            else
            {
                say += (cnt + '0');
                say += hear[i - 1];
                cnt = 1;
            }
        }

        return say;
    }
};