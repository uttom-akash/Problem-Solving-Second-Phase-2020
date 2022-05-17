#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, majority;

        for (auto num : nums)
        {
            if (cnt == 0)
            {
                majority = num;
            }

            cnt += majority == num ? +1 : -1;
        }

        return majority;
    }
};