#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
private:
    vector<int> dependancy[2005];
    int degree[2005];
    bool taken[2005];

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> ans;

        memset(degree, 0, sizeof(degree));
        memset(taken, 0, sizeof(taken));
        for (auto pre : prerequisites)
        {
            dependancy[pre[1]].push_back(pre[0]);
            degree[pre[0]]++;
        }

        stack<int> tracker;
        for (int i = 0; i < numCourses; i++)
        {
            if (degree[i] == 0)
            {
                tracker.push(i);
                taken[i] = 1;
            }
        }

        while (!tracker.empty())
        {
            auto u = tracker.top();
            tracker.pop();
            ans.push_back(u);

            for (auto v : dependancy[u])
            {
                if (--degree[v] == 0 and taken[v] == 0)
                {
                    tracker.push(v);
                    taken[v] = 1;
                }
            }
        }

        if (ans.size() == numCourses)
        {
            return ans;
        }
        else
        {
            return vector<int>();
        }
    }
};
