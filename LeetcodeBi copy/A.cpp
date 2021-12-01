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

class Solution
{
public:
    vector<pair<int, int>> adj[100005];
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[2] < b[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        sort(meetings.begin(), meetings.end(), comp);
        int sz = meetings.size();

        for (int i = 0; i < sz; i++)
        {
            int p1 = meetings[i][0];
            int p2 = meetings[i][1];
            int t = meetings[i][2];

            adj[p1].push_back({t, p2});
            adj[p2].push_back({t, p1});
        }

        set<int> secret;
        secret.insert(0);
        secret.insert(firstPerson);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        q.push({0, 0});
        q.push({0, firstPerson});

        while (!q.empty())
        {
            auto p1 = q.top();
            q.pop();

            for (int i = 0; i < adj[p1.second].size(); i++)
            {
                auto p2 = adj[p1.second][i];

                if (p1.first <= p2.first and secret.find(p2.second) == secret.end())
                {
                    q.push({p2.first, p2.second});
                    secret.insert(p2.second);
                }
            }
        }

        vector<int> ans;
        ans.assign(secret.begin(), secret.end());
        return ans;
    }
};
void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0, n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                a++;
            if (s[i] == 'B')
                b++;
            if (s[i] == 'C')
                c++;
        }

        if (a + c == b)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}