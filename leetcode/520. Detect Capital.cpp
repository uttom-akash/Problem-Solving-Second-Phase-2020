#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int capLetters = 0, smallLetters = 0;
        int sz = word.size();
        bool firstCap = false;

        for (int i = 0; i < sz; i++)
        {
            char c = word[i];

            if (isupper(c))
            {
                capLetters++;
                if (i == 0)
                    firstCap = true;
            }
            else
            {
                smallLetters++;
            }
        }

        return ((capLetters == 1 and firstCap) || capLetters == sz || smallLetters == sz);
    }
};