#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> v;
        int n = digits.size();

        if (n == 0)
        {
            return v;
        }

        queue<string> q;
        q.push("");

        for (char dig : digits)
        {
            auto mp = getMapping(dig);
            int sz = q.size();

            int i = 0;
            while (i++ < sz)
            {
                auto currStr = q.front();
                q.pop();
                for (auto i = 0; i < mp.second; i++)
                {
                    char c = static_cast<char>(mp.first + i);
                    q.push(currStr + c);
                }
            }
        }

        while (!q.empty())
        {
            auto currStr = q.front();
            q.pop();
            v.push_back(currStr);
        }

        return v;
    }

    pair<char, int> getMapping(char c)
    {
        map<char, pair<char, int>> mp;

        mp['2'] = {'a', 3};
        mp['3'] = {'d', 3};
        mp['4'] = {'g', 3};
        mp['5'] = {'j', 3};
        mp['6'] = {'m', 3};
        mp['7'] = {'p', 4};
        mp['8'] = {'t', 3};
        mp['9'] = {'t', 4};

        return mp[c];
    }
};