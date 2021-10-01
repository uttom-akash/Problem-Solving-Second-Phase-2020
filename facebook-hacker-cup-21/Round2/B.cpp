#include <bits/stdc++.h>

#define mx 800005
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "data/input.txt", string fout = "data/Boutput.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

vector<int> adj[mx];
bool visited[mx];
int freq[mx], freqCounter[mx];

void dfs1(int u)
{
    visited[u] = true;
    int f = freq[u];
    freqCounter[f]++;
    int nn = adj[u].size();
    for (int i = 0; i < nn; i++)
    {
        int v = adj[u][i];
        if (visited[v] == false)
        {
            dfs1(v);
        }
    }
}

int dfs2(int u)
{
    visited[u] = true;
    int nn = adj[u].size();
    int ans = 0;
    for (int i = 0; i < nn; i++)
    {
        int v = adj[u][i];
        if (visited[v] == false)
        {
            ans += dfs2(v);
            int f = freq[v];
            freqCounter[f]--;
            if (freqCounter[f] == 0)
            {
                ans++;
            }
        }
    }

    return ans;
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            freqCounter[i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> freq[i];
        }

        dfs1(0);

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        int ans = dfs2(0);
        cout << "Case #" << tc << ": " << ans << "\n";

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}