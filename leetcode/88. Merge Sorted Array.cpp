#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0,k=m;
        
        for(int ii=0;ii<n+m;ii++){
            
            if(i>=m)
            {
                nums1[k++]=nums2[j++];
            }
            else if(j>=n)
            {
                break;  
            }
            else if(nums1[i]<nums2[j])
            {
                nums1[k++]=nums1[i++];       
            }
            else{
                nums1[k++]=nums2[j++];    
            }
            
            k=k%(m+n);
        }
        
        reverse(nums1,0,m-1);
        reverse(nums1,m,m+n-1);
        reverse(nums1,0,m+n-1);
        
        
    }
    
    void reverse(vector<int>& nums, int start, int end){
        
       
        int mid = (start+end+1)>>1;
        
        while(start < mid){
            swap(nums[start],nums[end]);
            start++,end--;
        }
    }
};