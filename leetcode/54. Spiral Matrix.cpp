#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int left = 0, top = 0;
        int right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        int direction = 0;
        vector<int> ans;

        while (left <= right && top <= bottom)
        {
            switch (direction % 4)
            {
            case 0:
                for (int i = left; i <= right; i++)
                    ans.push_back(matrix[top][i]);
                direction++;
                top++;
                break;
            case 1:
                for (int i = top; i <= bottom; i++)
                    ans.push_back(matrix[i][right]);
                direction++;
                right--;
                break;
            case 2:
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                direction++;
                bottom--;
                break;
            case 3:
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[left][i]);
                direction++;
                left++;
                break;
            }
        }

        return ans;
    }
};