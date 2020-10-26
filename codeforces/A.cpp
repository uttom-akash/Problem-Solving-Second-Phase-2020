#include<bits/stdc++.h>
#define ll long long

using namespace std;

void printSeq(int l,int val){
    cout<<l<<"\n";
    for(int i=0;i<l;i++)
        cout<<val<<" ";
    cout<<"\n";
}

int main(int argc, char const *argv[])
{
    int tests;
    cin>>tests;

    while (tests--)
    {
        int n;
        cin>>n;
        int seq[n+5],zeros=0,half=n/2;
        
        for(int i=0;i<n;i++){
            cin>>seq[i];
            if(!seq[i])
                zeros++;
        }   

        if(zeros<half){
            if(half%2){
                printSeq(half+1,1);
            }else{
                printSeq(half,1);
            }
        }else {
            printSeq(half,0);
        }
    }

    return 0;
}
