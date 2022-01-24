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
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {

            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int res = tokens[i] == "+" ? a + b : tokens[i] == "-" ? a - b
                                                 : tokens[i] == "*"   ? a * b
                                                                      : a / b;
                st.push(res);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
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
        cout << s << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}