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

void setupFileIO(string fin = "data/consistency_chapter_2_input.txt", string fout = "data/A2output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

void setMinDistance(int dist[][30], int nNode)
{

    for (int k = 0; k < nNode; k++)
    {
        for (int i = 0; i < nNode; i++)
        {
            for (int j = 0; j < nNode; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void makeGraph(int graph[][30], string edges[], int nEdge, int nNode)
{
    for (int i = 0; i < nNode; i++)
    {
        for (int j = 0; j < nNode; j++)
        {
            graph[i][j] = INT_MAX;
        }

        graph[i][i] = 0;
    }

    for (int i = 0; i < nEdge; i++)
    {
        int u = edges[i][0] - 'A';
        int v = edges[i][1] - 'A';

        graph[u][v] = 1;
    }
}

int getMinSeconds(int dist[][30], string s)
{
    int l = s.size();
    int ans = INT_MAX;
    for (int v = 0; v < 26; v++)
    {
        int mAns = 0;
        for (int j = 0; j < l; j++)
        {
            int u = s[j] - 'A';
            if (dist[u][v] == INT_MAX)
            {
                mAns = INT_MAX;
                break;
            }
            mAns += dist[u][v];
        }
        ans = min(ans, mAns);
    }

    return ans;
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        string s;
        int nEdge, nNode = 26;
        cin >> s >> nEdge;

        string edges[nEdge + 5];

        for (int i = 0; i < nEdge; i++)
        {
            cin >> edges[i];
        }

        int graph[30][30];
        makeGraph(graph, edges, nEdge, nNode);
        setMinDistance(graph, nNode);
        int seconds = getMinSeconds(graph, s);
        if (seconds == INT_MAX)
            cout << "Case #" << tc << ": " << -1 << "\n";
        else
            cout << "Case #" << tc << ": " << seconds << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}