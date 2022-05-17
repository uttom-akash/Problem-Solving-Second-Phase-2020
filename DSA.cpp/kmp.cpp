#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;



void fillLps(string pattern,int sz, int lps[]){
    int i=0,j=1;
    lps[0]=0;

    while(j<sz){
        if(pattern[i]==pattern[j]){
            lps[j]=i+1;
            i++,j++;
        }else{
            if(i==0){
                lps[j]=0;
                j++;
            }else{
                i=lps[i-1];            
            }       
        }
    }
}


// aabcaab
// 0100123
// aaabcaab

int kmp(string text, string pattern){
    int szt = text.size(), szp = pattern.size();
    int lps[100];

    fillLps(pattern,szp,lps);

    int i=0,j=0;

    while (i<szt)
    {
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j==0){
                i++;
            }else{
                j=lps[j-1];
            }
        }

        if(j==szp){
            cout<<"matched: "<<i-j+1<<"\n";
            j=lps[j-1];
        }
    }
    
    return -1;
}


int main(int argc, char const *argv[])
{
    kmp("aaabcaab","aabcaab");
    return 0;
}


