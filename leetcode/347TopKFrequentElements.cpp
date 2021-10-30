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

struct NumInfo
{
    int value, frequency;

    NumInfo(int value, int frequency)
    {
        this->value = value;
        this->frequency = frequency;
    }

    bool operator<(const NumInfo &info)
    {
        return this->frequency > info.frequency;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> mapper;
        vector<NumInfo> temp;
        vector<int> ans;

        for (size_t i = 0; i < n; i++)
        {
            int num = nums[i];
            mapper[num]++;
        }

        for (auto it = mapper.begin(); it != mapper.end(); it++)
        {
            temp.push_back(NumInfo(it->first, it->second));
        }

        sort(temp.begin(), temp.end());

        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            ans.push_back(it->value);
            if (ans.size() == k)
                break;
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
        string s;
        cin >> s;
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}