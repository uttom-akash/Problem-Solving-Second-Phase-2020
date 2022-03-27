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
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, sz1 = nums1.size(), sz2 = nums2.size();
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        ans.push_back(vector<int>());

        while (i < sz1 || j < sz2)
        {
            while (i + 1 < sz1 and nums1[i] == nums1[i + 1])
            {
                i++;
            }

            while (j + 1 < sz2 and nums2[j] == nums2[j + 1])
            {
                j++;
            }

            if (i >= sz1)
            {
                ans[1].push_back(nums2[j++]);
            }
            else if (j >= sz2)
            {
                ans[0].push_back(nums1[i++]);
            }
            else if (nums1[i] < nums2[j])
            {
                ans[0].push_back(nums1[i++]);
            }
            else if (nums1[i] > nums2[j])
            {
                ans[1].push_back(nums2[j++]);
            }
            else
            {
                i++, j++;
            }
        }

        return ans;
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}