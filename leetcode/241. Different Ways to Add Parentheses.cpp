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

/*
  2*3-4*5
  2 3 4 5
  + * - *
  
  2 - - -
  - 3 - -
  - - 4 -
  - - - 5
  
  2 6 -2,10 -
  - 3 -1    -
  - -  4    -
  - -  -    5
   
  2  
*/

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {

        auto exp = preprocessExp(expression);

        int length = exp.first.size();

        vector<int> mcm[length][length];

        for (int L = 1; L <= length; L++)
        {
            for (int lo = 0; lo + L - 1 < length; lo++)
            {
                int hi = lo + L - 1;

                if (lo == hi)
                {
                    mcm[lo][hi].push_back(exp.first[lo]);
                    continue;
                }

                for (int mid = lo; mid < hi; mid++)
                {
                    int lhs = mcm[lo][mid].size();
                    int rhs = mcm[mid + 1][hi].size();

                    for (int ii = 0; ii < lhs; ii++)
                    {
                        for (int ji = 0; ji < rhs; ji++)
                        {
                            int eval = evaluate(mcm[lo][mid][ii], exp.second[mid + 1], mcm[mid + 1][hi][ji]);
                            mcm[lo][hi].push_back(eval);
                        }
                    }
                }
            }
        }

        return mcm[0][length - 1];
    }

    int evaluate(int a, char op, int b)
    {
        int ans;
        switch (op)
        {
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        default:
            ans = a * b;
            break;
        }

        return ans;
    }

    pair<vector<int>, vector<char>> preprocessExp(string expression)
    {
        vector<int> nums;
        vector<char> ops;
        int i = 0;

        if (!('0' <= expression[i] && expression[i] <= '9'))
        {
            ops.push_back(expression[i]);
            i++;
        }
        else
        {
            ops.push_back('+');
        }

        int num = 0;

        for (; i < expression.size(); i++)
        {
            if ('0' <= expression[i] && expression[i] <= '9')
            {
                num = num * 10 + (expression[i] - '0');
            }
            else
            {
                nums.push_back(num);
                num = 0;
                ops.push_back(expression[i]);
            }
        }

        nums.push_back(num);

        return {nums, ops};
    }
};

void solve()
{

    Solution s;
    s.diffWaysToCompute("2*3-4*5");
}

int main()
{
    optimize();

    solve();

    return 0;
}