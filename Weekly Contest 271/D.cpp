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

struct CustomCompare
{
    bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs)
    {
        if (lhs.second > rhs.second)
            return true;
        if (lhs.second < rhs.second)
            return false;

        return lhs.first > rhs.first;
    }
};

class SORTracker
{
private:
    priority_queue<pair<string, int>, vector<pair<string, int>>, CustomCompare> pq;

public:
    SORTracker()
    {
    }

    void add(string name, int score)
    {
        pq.push({name, score});
    }

    string get()
    {
        auto ans = pq.top();
        pq.pop();
        return ans.first;
    }
};

void solve()
{
    SORTracker s;
}

int main()
{
    optimize();

    solve();

    return 0;
}