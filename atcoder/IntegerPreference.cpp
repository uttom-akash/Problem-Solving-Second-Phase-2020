#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isOverlaped(ll a,ll b,ll c,ll d){
    if(b<c)
        return false;
    if(d<a)
        return false;
        
    return true ;
}

int main(int argc, char const *argv[])
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    if(isOverlaped(a,b,c,d))
        cout<<"Yes\n";
    else 
        cout<<"No\n";

    return 0;
}
