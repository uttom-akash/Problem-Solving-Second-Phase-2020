#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        queue<string> q;
        q.push("(");

        for (int i = 1; i < 2 * n; i++)
        {
            int j = 0, qSz = q.size();
            while (j < qSz)
            {
                string left = q.front();
                q.pop();

                if (i < 2 * n - 1)
                    q.push(left + '(');
                
                if(isValid(left + ')')>=0)
                    q.push(left + ')');

                j++;
            }
        }

        vector<string> ans;

        while (!q.empty())
        {
            string comb = q.front();
            q.pop();
            if (isValid(comb)==0)
            {
                ans.push_back(comb);
            }
        }

        return ans;
    }

    int isValid(string comb)
    {
        int balance = 0;

        for (char c : comb)
        {
            if (c == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return balance;
        }

        return balance;
    }
};