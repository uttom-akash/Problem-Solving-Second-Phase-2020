#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int sz = s.size();
        int left = 0, right = sz - 1;

        while (left < right)
        {
            if (!isAlphaNumeric(s[left]))
            {
                left++;
            }
            else if (!isAlphaNumeric(s[right]))
            {
                right--;
            }
            else
            {
                if (toLower(s[left]) != toLower(s[right]))
                {
                    return false;
                }

                left++, right--;
            }
        }

        return true;
    }

    char toLower(char c)
    {
        if ('A' <= c and c <= 'Z')
            return (c - 'A') + 'a';

        return c;
    }

    bool isAlphaNumeric(char c)
    {
        return ('a' <= c and c <= 'z') || ('A' <= c and c <= 'Z') || ('0' <= c and c <= '9');
    }
};