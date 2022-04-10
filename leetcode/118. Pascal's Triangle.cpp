#include <vector>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascalTriangle(numRows);
        pascalTriangle[0] = vector<int>({1});

        for (int row = 1; row < numRows; row++)
        {
            pascalTriangle[row] = vector<int>(row + 1);

            for (int col = 0; col <= row; col++)
            {
                pascalTriangle[row][col] = 0;
                pascalTriangle[row][col] += col <= row - 1 ? pascalTriangle[row - 1][col] : 0;
                pascalTriangle[row][col] += col - 1 >= 0 ? pascalTriangle[row - 1][col - 1] : 0;
            }
        }

        return pascalTriangle;
    }
};