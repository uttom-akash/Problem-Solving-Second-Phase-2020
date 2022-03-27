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

vector<int> adjMatrix[mx];
int dist[mx];

void doBfs(int h)
{
    queue<int> q;
    q.push(h);
    dist[h] = 0;

    while (!q.empty())
    {
        auto parent = q.front();
        q.pop();

        for (auto child : adjMatrix[parent])
        {
            if (dist[parent] + 1 > dist[child])
                continue;

            dist[child] = dist[parent] + 1;
            q.push(child);
        }
    }
}

int solution(int N, vector<int> &A, vector<int> &B, vector<int> &H)
{
    int m = A.size();
    int L = H.size();

    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < m; i++)
    {
        adjMatrix[A[i]].push_back(B[i]);
        adjMatrix[B[i]].push_back(A[i]);
    }

    for (int i = 0; i < L; i++)
    {
        doBfs(H[i]);
    }

    int ans = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, dist[i]);
    }

    return ans == INT_MAX ? -1 : ans;
}

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        string s;
        cin >> s;
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}