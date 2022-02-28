#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        map<string, int> wordfreq, windowfreq;
        vector<int> ans;
        int strSize = s.size();
        int wordListSize = words.size();
        int wordSize = words[0].size();
        int subSize = wordSize * wordListSize;
        int wordUsed = 0;

        for (auto word : words)
        {
            wordfreq[word]++;
        }

        for (int i = 0; i < wordSize; i++)
        {
            wordUsed = 0;
            windowfreq.clear();
            int left = i;

            for (int right = left; right + wordSize <= strSize; right += wordSize)
            {

                string word = s.substr(right, wordSize);
                if (wordfreq[word] == 0)
                {
                    wordUsed = 0;
                    left = right + wordSize;
                    windowfreq.clear();
                }
                else
                {

                    while (right - left == subSize || windowfreq[word] >= wordfreq[word])
                    {
                        auto leftWord = s.substr(left, wordSize);
                        left += wordSize;

                        windowfreq[leftWord]--;
                        wordUsed--;

                    }

                    windowfreq[word]++;
                    wordUsed++;

                    if (wordUsed == wordListSize)
                    {
                        ans.push_back(left);
                    }
                }
            }
        }

        return ans;
    }
};