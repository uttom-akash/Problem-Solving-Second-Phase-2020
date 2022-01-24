#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

// fill_n(&a[0][0], ntc * ntc, -100);

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "input.txt", string fout = "output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

#define way4                               \
    (int[4][2])                            \
    {                                      \
        {0, 1}, {1, 0}, {0, -1}, { -1, 0 } \
    }

struct Cell{
    int dist;
    int price;
    int row,col;

    bool operator<(const Cell &a)
    {
        if(dist!=a.dist){
            return dist<a.dist;
        }

        if(price!=a.price){
            return price<a.price;
        }

        if(row!=a.row){
            return row<a.row;
        }

        if(col!=a.col){
            return col<a.col;
        }

        return false;
    }
};

class Solution {

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        queue<pair<int,int>> bfs;
        vector<Cell>meta;
        int n=grid.size(),m=grid[0].size();
        int vis[n+5][m+5];
        
        memset(vis,-1,sizeof(vis));

        bfs.push({start[0],start[1]});
        vis[start[0]][start[1]]=0;

        while (!bfs.empty())
        {
            auto u=bfs.front();
            bfs.pop();

            if(grid[u.first][u.second]>1 and grid[u.first][u.second]>=pricing[0] and grid[u.first][u.second]<=pricing[1]){
                        Cell c;
                        c.dist=vis[u.first][u.second];
                        c.price=grid[u.first][u.second];
                        c.row=u.first;
                        c.col=u.second;
                        meta.push_back(c);
            }

            for(auto way:way4){
                auto v=make_pair(u.first+way[0],u.second+way[1]);
                
                if(v.first<0 || v.first>=n || v.second<0 || v.second>=m)
                    continue;

                
                if(vis[v.first][v.second]==-1 and grid[v.first][v.second]>0){
                    bfs.push(v);
                    vis[v.first][v.second]=vis[u.first][u.second]+1;
                }
            }
        }
        
        sort(meta.begin(),meta.end());
        vector<vector<int>> ans;
        
        int ii=0;
        for (auto m: meta )
        {
            ans.push_back(vector<int>{m.row,m.col});
            
            ii++;
            if(ii==k){
                break;
            }
        }
        return ans;
    }
};


void solve()
{

    ll n;
    cin >> n;
    ll ans = 0;

    for (int i = 1; i * i * i <= n; i++)
    {
        if (n % i != 0)
        {
            continue;
        }

        for (int j = i; i * j * j <= n; j++)
        {
            if (n % (1LL * i * j) != 0)
            {
                continue;
            }

            for (int k = j; i * j * k <= n; k++)
            {
                if (n % (1LL * i * j * k) != 0)
                {
                    continue;
                }

                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}