#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz= nums.size();
        int mcm[sz+1][sz+1];

        memset(mcm,0,sizeof(mcm));
        
        for (int l = 1; l <=sz; l++)
        {
            for (int i = 0; i+l-1 < sz; i++)
            {
                int j = i+l-1;

                for (int k = i; k <=j; k++)
                {
                    int leftBaloon = 1, rightBaloon=1,leftValue=0,rightValue=0;
                    
                    if(i>0){
                        leftBaloon=nums[i-1];
                    }

                    if(j+1<sz){
                        rightBaloon=nums[j+1];
                    }

                    if(i<=k-1){
                        leftValue=mcm[i][k-1];
                    }

                    if(k+1<=j){
                        rightValue=mcm[k+1][j];
                    }

                    mcm[i][j]= max(mcm[i][j],leftValue+rightValue+leftBaloon*nums[k]*rightBaloon);

                }
                
            }
            
        }
        
        return mcm[0][sz-1];
    }
};