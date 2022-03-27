#include <bits/stdc++.h>

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

#define mx 100005

int indegree[mx];
vector<int> dependancy[mx];

void setTwoLargestIndependantV(int *largestIndependentV, int *secondLargestV, int v)
{
    if (v >= *largestIndependentV)
    {
        *secondLargestV = *largestIndependentV;
        *largestIndependentV = v;
    }
    else
    {
        *secondLargestV = max(*secondLargestV, v);
    }
}

int produceMaxValue(int n, int m, vector<int> &V)
{
    queue<int> q;
    int ans = INT_MIN;
    int largestIndependentV = INT_MIN, secondLargestV = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            setTwoLargestIndependantV(&largestIndependentV, &secondLargestV, V[i]);
            q.push(i);
        }
    }

    // if we do independant project
    ans = max(ans, largestIndependentV);
    if (secondLargestV != INT_MIN)
        ans = max(ans, largestIndependentV + secondLargestV);

    while (!q.empty())
    {
        auto parent = q.front();
        q.pop();

        for (auto child : dependancy[parent])
        {
            indegree[child]--;

            if (indegree[child] != 0)
            {
                indegree[child] =-1;
                continue;
            }

            // dependant twoProject
            int twoProjectsValue = V[parent] + V[child];
            ans = max(ans, twoProjectsValue);
        }
    }

    return max(ans, 0);
}

int solution(vector<int> &V, vector<int> &A, vector<int> &B)
{
    int n = V.size();
    int m = A.size();

    for (int i = 0; i < m; i++)
    {
        dependancy[A[i]].push_back(B[i]);
        indegree[B[i]]++;
    }

    return produceMaxValue(n, m, V);
}

void solve()
{
}

int main()
{
    optimize();

    solve();

    return 0;
}