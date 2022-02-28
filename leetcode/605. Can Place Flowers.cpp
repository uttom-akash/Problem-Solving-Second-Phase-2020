#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0, previ=0;
        int sz= flowerbed.size();

        int i=0;
        while (i<sz)
        {
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i+1==sz || flowerbed[i+1]==0)){
                i+=2;
                ans++;
            }else{
                i++;
            }
        }
        
        return n<=ans;

    }
};