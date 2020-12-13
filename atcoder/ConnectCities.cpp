#include<bits/stdc++.h>
#define ll long long

using namespace std;


int vis[100005];
vector<int> edge[100005];


void dfs(int s){
    stack<int>st;
    st.push(s);
    while (!st.empty())
    {
        int node=st.top();st.pop();
        vis[node]=1;
        for(int i=0;i<edge[node].size();i++){
            int child=edge[node][i];
            if(vis[child]==0)
                st.push(child);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    for(int i=1;i<=100000;i++)
        {
            vis[i]=0;
        }
    

    int N,M;
    cin>>N>>M;
    while (M--)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=N;i++)
    {
        if(vis[i]==0){
            ans++;
            dfs(i);
        }
    }       
    cout<<ans-1<<"\n";
    return 0;
}