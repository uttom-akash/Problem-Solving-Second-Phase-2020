#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

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

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    int topologicalSort()
    {
        vector<int> in_degree(V, 0);
        vector<int> needRead(V, 0);

        for (int u = 0; u < V; u++)
        {
            list<int>::iterator itr;
            for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
                in_degree[*itr]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (in_degree[i] == 0)
            {
                q.push(i);
                in_degree[i]--;
            }

        int cnt = 0, timesRead = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            list<int>::iterator itr;
            int small = INT_MAX;
            for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
            {
                int v = *itr;
                if (--in_degree[*itr] == 0)
                {
                    q.push(*itr);
                    small = min(*itr, small);
                }
            }
            if (small < u)
            {
                needRead[small] = 1;
            }
            timesRead += needRead[u];
            cnt++;
        }

        if (cnt != V)
        {
            return -1;
        }
        else
        {
            return timesRead;
        }
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        int n;
        cin >> n;
        Graph g(n);

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;

            for (int j = 0; j < k; j++)
            {
                int u;
                cin >> u;
                g.addEdge(u - 1, i);
            }
        }

        int ans = g.topologicalSort();

        cout << ans << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}