#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
private:
    vector<vector<string>> partitions;
    int dp[17][17];

public:
    vector<vector<string>> partition(string s)
    {
        vector<string> substrings;
        checkAllPartitions(substrings, s, 0, s.size());

        return partitions;
    }

    void checkAllPartitions(vector<string> &substrings, string &s, int pos, int n)
    {
        if (pos == n)
        {
            partitions.push_back(substrings);
            return;
        }

        string currSub = "";
        for (int i = pos; i < n; i++)
        {
            currSub += s[i];

            if (s[pos] == s[i] and (i - pos <= 2 || dp[pos + 1][i - 1]))
            {
                dp[pos][i] = true;
                substrings.push_back(currSub);
                checkAllPartitions(substrings, s, i + 1, n);
                substrings.pop_back();
            }
        }
    }
};