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
    int minDeletion(vector<int> &nums)
    {
        int deleted = 0;
        int sz = nums.size();
        int i = 0;

        while (i < sz)
        {
            if ((i - deleted) % 2 == 1)
            {

                i++;
                continue;
            }

            while (i + 1 < sz and nums[i] == nums[i + 1])
            {
                i++;
                deleted++;
            }

            i++;
        }

        if ((sz - deleted) % 2 == 1)
            deleted++;

        return deleted;
    }
};

int main()
{
    optimize();

    return 0;
}