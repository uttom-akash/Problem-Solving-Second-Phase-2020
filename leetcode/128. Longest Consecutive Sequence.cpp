#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

// fill_n(&a[0][0], ntc * ntc, -100);

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "input.txt", string fout = "output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> numset;

        for (auto num : nums)
        {
            numset.insert(num);
        }

        int ans = 0;
        for (auto num : numset)
        {
            if (numset.find(num - 1) == numset.end())
            {
                int currAns = 1;
                int currNum = num;

                while (numset.find(currNum + 1) != numset.end())
                {
                    currAns++;
                    currNum++;
                }

                ans = max(ans, currAns);
            }
        }

        return ans;
    }
};

void solve()
{

    Solution s;
    vector<int> v{1, 2, -1};
    s.longestConsecutive(v);
}

int main()
{
    optimize();

    solve();

    return 0;
}