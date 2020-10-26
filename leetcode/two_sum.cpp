#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>secondNum;
        vector<int>ans;

        int length=nums.size();
        for(int i=0;i<length;i++){
            secondNum[target-nums[i]]=i+1;
        }
        
        for(int i=0;i<length;i++){
            if(secondNum[nums[i]]>0){
                ans.push_back(secondNum[nums[i]]-1);
                ans.push_back(i);
                break;
            }            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int>nums({2,7,11,15});
    Solution s;
    s.twoSum(nums,9);
    return 0;
}
