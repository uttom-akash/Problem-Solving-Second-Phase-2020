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
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int N = nums.size();
        int *arrNums = nums.data();
        vector<vector<int>> triplets;

        sort(arrNums, arrNums + N);

        for (size_t i = 0; i < N; i++)
        {
            cout << arrNums[i] << "\n";
        }

        for (int i = 0; i < N - 2; i++)
        {
            for (int j = i + 1; j < N - 1; j++)
            {
                int third = 0 - (arrNums[i] + arrNums[j]);
                int index = upper_bound(arrNums + j + 1, arrNums + N, third) - arrNums - 1;

                if (index <= j || arrNums[index] != third)
                    continue;

                triplets.push_back(vector<int>({arrNums[i], arrNums[j], arrNums[index]}));

                while (j < N - 2 && arrNums[j] == arrNums[j + 1])
                    j++;
            }

            while (i < N - 3 && arrNums[i] == arrNums[i + 1])
                i++;
        }

        return triplets;
    }
};

void solve()
{
    vector<int> v({-13, 5, 13, 12, -2, -11, -1, 12, -3, 0, -3, -7, -7, -5, -3, -15, -2, 14, 14, 13, 6, -11, -11, 5, -15, -14, 5, -5, -2, 0, 3, -8, -10, -7, 11, -5, -10, -5, -7, -6, 2, 5, 3, 2, 7, 7, 3, -10, -2, 2, -12, -11, -1, 14, 10, -9, -15, -8, -7, -9, 7, 3, -2, 5, 11, -13, -15, 8, -3, -7, -12, 7, 5, -2, -6, -3, -10, 4, 2, -5, 14, -3, -1, -10, -3, -14, -4, -3, -7, -4, 3, 8, 14, 9, -2, 10, 11, -10, -4, -15, -9, -1, -1, 3, 4, 1, 8, 1});
    Solution s;
    s.threeSum(v);
}

int main()
{
    optimize();

    solve();

    return 0;
}
