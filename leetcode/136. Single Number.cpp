#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int xsum = 0;

        for (auto num : nums)
        {
            xsum ^= num;
        }
        
        return xsum;
    }
};