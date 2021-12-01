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
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<int> v;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                v.push_back(i);
        }

        return v;
    }
};

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int sz = nums.size();
        vector<int> ans;
        int psum[sz + 5];
        psum[0] = 0;

        for (size_t i = 0; i < sz; i++)
        {
            psum[i + 1] = psum[i] + nums[i];
        }

        for (size_t i = 0; i < sz; i++)
        {
            if (i - k < 0 || i + k >= sz)
            {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(psum[i + k + 1] - psum[i - k]);
        }

        return ans;
    }
};

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int minI = 0, maxI = 0;
        int mi = INT_MAX, mm = INT_MIN;
        int sz = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (mi > nums[i])
            {
                mi = nums[i];
                minI = i;
            }

            if (mm < nums[i])
            {
                mm = nums[i];
                maxI = i;
            }
        }

        int ans = INT_MAX;
        if (minI == maxI)
        {
            ans = min(minI + 1, sz - minI);
        }
        else
        {
            int diff = abs(minI - maxI);

            ans = min(ans, min(minI + 1, sz - minI) + min(maxI + 1, sz - maxI));
            ans = min(ans, min(minI + 1, sz - minI) + diff);
            ans = min(ans, min(maxI + 1, sz - maxI) + diff);
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
        int n;
        cin >> n;
        int a[100 + 5], sa[100 + 5];
        unordered_map<int, int> mapper;
        vector<pair<int, pair<int, int>>> ans;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sa[i] = a[i];
            mapper[a[i]]++;
        }

        sort(sa, sa + n);

        for (int i = 0; i < n; i++)
        {
            int index = upper_bound(sa, sa + n, a[i]) - sa;
            index -= mapper[a[i]]--;

            int shift = (i - index + n) % n;
        }
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}