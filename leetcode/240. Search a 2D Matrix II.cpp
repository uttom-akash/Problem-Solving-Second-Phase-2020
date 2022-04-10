#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution1
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int sz = matrix.size();

        return DnQ(0, sz - 1, matrix, target);
    }

    bool DnQ(int lo, int hi, vector<vector<int>> &matrix, int target)
    {
        if (lo == hi)
        {
            return binary_search(matrix[lo].begin(), matrix[lo].end(), target);
        }

        int mid = (lo + hi) >> 1;
        bool ans = false;
        if (isTargetInRange(lo, mid, matrix, target))
        {
            ans |= DnQ(lo, mid, matrix, target);
        }

        if (isTargetInRange(mid + 1, hi, matrix, target))
        {
            ans |= DnQ(mid + 1, hi, matrix, target);
        }

        return ans;
    }

    bool isTargetInRange(int lo, int hi, vector<vector<int>> &matrix, int target)
    {
        return matrix[lo][0] <= target and target <= matrix[hi][matrix[hi].size() - 1];
    }
};


int main(int argc, char const *argv[])
{

    return 0;
}
