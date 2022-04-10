#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
private:
    vector<string> res;

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        sort(wordDict.begin(), wordDict.end());

        checkPossibleBreakedWord(s, "", wordDict, 0, s.size());

        return res;
    }

    void checkPossibleBreakedWord(string s, string segStr, vector<string> &wordDict, int currP, int n)
    {

        if (currP == n)
        {
            res.push_back(segStr);
            return;
        }

        string currSub = "";
        for (int i = currP; i < n; i++)
        {
            currSub += s[i];
            if (doBinarySearch(wordDict, currSub))
            {
                auto temp = segStr.size() ? segStr + " " + currSub : currSub;
                checkPossibleBreakedWord(s, temp, wordDict, i + 1, n);
            }
        }
    }

    bool doBinarySearch(vector<string> &list, string key)
    {
        int lo = 0, hi = list.size() - 1, mid;

        while (lo <= hi)
        {
            mid = (lo + hi) >> 1;

            if (list[mid] == key)
            {
                return true;
            }
            else if (list[mid] < key)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }

        return false;
    }
};