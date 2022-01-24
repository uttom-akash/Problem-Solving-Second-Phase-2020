#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        int sz = s.size();
        string ss = inception(s, 0, sz - 1, 1);

        return ss;
    }

    string inception(string s, int lo, int hi, int rep)
    {
        string ss = "";
        int i = lo;
        while (i <= hi)
        {

            if ('0' <= s[i] and s[i] <= '9')
            {
                int k = 0;
                while (i <= hi and '0' <= s[i] and s[i] <= '9')
                {
                    k = k * 10 + (int)(s[i] - '0');
                    i++;
                }

                int lft = ++i, openBracket = 1;
                while (i <= hi and openBracket != 0)
                {

                    if (s[i] == ']')
                        openBracket--;
                    if (s[i] == '[')
                        openBracket++;

                    i++;
                }
                ss += inception(s, lft, i - 2, k);
            }
            else
            {

                ss += s[i++];
            }
        }

        return getRepeated(ss, rep);
    }

    string getRepeated(string s, int rep)
    {
        string ans = "";
        while (rep--)
        {
            ans += s;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    return 0;
}
