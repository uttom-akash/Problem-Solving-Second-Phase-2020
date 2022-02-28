#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        string mp[30];
        stringstream ss(s);

        string word;
        int i = 0;
        while (ss >> word)
        {
            if(i>=pattern.size()){
                return false;
            }

            bool alreadyMapped = false;
            for (size_t i = 0; i < 26; i++)
            {
                if (mp[i] == word)
                {
                    alreadyMapped = true;
                }
            }

            int c = (int)(pattern[i++] - 'a');
            if (!alreadyMapped and mp[c] == "")
            {
                mp[c] = word;
            }

            if (mp[c] != word)
            {
                return false;
            }
        }

        return i==pattern.size() ? true : false;
    }
};