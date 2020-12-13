#include<bits/stdc++.h>
#define ll long long

using namespace std;

int gcd(int a,int b){
    while (a && b)
    {
        if(a>b)a=a%b;
        else b=b%a;
    }

    return a+b;
}

int main(int argc, char const *argv[])
{
    int tests;
    cin>>tests;
    while (tests--)
    {
       int n;
       cin>>n;
       int maxI=0,curGcd=0,nums[n+5],b[n+5];

       for(int i=0;i<n;i++){
           cin>>nums[i];
           maxI=nums[i]>nums[maxI] ? i : maxI;
       } 

       curGcd=nums[maxI];
       b[0]=nums[maxI];
       nums[maxI]=0;

       for(int i=1;i<n;i++){
           int maxGcd=0;
           for(int j=0;j<n;j++){
               int g=gcd(nums[j],curGcd);
               if(nums[j] && g>maxGcd){
                   maxI=j;
                   maxGcd=g;
               }
           }
           b[i]=nums[maxI];
           nums[maxI]=0;
           curGcd=maxGcd;
       }
       for (int i = 0; i < n; i++)
         {
             cout << b[i] << ' ';
         }
        cout << '\n';   
    }
    
    return 0;
}
