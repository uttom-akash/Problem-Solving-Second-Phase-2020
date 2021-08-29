#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base ::sync_with_stdio(false);
}

void setupFileIO(string fin = "input.txt", string fout = "output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> _stack;
        int length = s.size();

        for (int i = 0; i < length; i++)
        {
            if (!_stack.empty() && isPair(_stack.top(), s[i]))
            {
                _stack.pop();
            }
            else
            {
                _stack.push(s[i]);
            }
        }

        return _stack.empty();
    }

    bool isPair(char p1, char p2)
    {
        if (p1 == '(' and p2 == ')')
        {
            return true;
        }
        if (p1 == '{' and p2 == '}')
        {
            return true;
        }
        if (p1 == '[' and p2 == ']')
        {
            return true;
        }

        return false;
    }
};

int main()
{
    optimize();

    Solution s;

    cout << s.isValid("()[{()()}]") << "\n";

    return 0;
}