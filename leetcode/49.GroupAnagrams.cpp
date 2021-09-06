#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        int cnt = strs.size();
        unordered_map<string, int> mapper;
        vector<vector<string>> ans;
        int grpId = 1;

        for (int i = 0; i < cnt; i++)
        {
            string curr = strs[i];
            sort(curr.begin(), curr.end());

            if (mapper[curr] == 0)
            {
                mapper[curr] = grpId;
                grpId++;
                ans.push_back(vector<string>());
            }
            ans[mapper[curr] - 1].push_back(strs[i]);
        }

        return ans;
    }
};

void solve()
{
    vector<string> v({"eat", "tea", "tan", "ate", "nat", "bat"});
    Solution s;
    s.groupAnagrams(v);
}

int main()
{
    optimize();

    solve();

    return 0;
}