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

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        queue<int> q1;
        q1.push(-1);
        for (int i = 0; i < n; i++)
        {
            q1.push((s[i] - '0'));
        }
        int sz = q1.size();

        while (true)
        {
            if (q1.size() >= 2)
            {
                int a = q1.front();
                q1.pop();

                int b = q1.front();
                
                if (a != -1 and b != -1 and (b - a == 1 || (a == 9 and b == 0)))
                {
                    int &tmp = q1.front();
                    tmp=(b + 1) % 10;
                }
                else
                {
                    q1.push(a);
                }
            }

            if (q1.front() == -1 and q1.size() == sz)
            {
                break;
            }

            if (q1.front() == -1)
            {
                sz = q1.size();
            }

        //     queue<int> q2(q1);
        //     while (!q2.empty())
        //     {
        //         cout << q2.front() << " ";
        //         q2.pop();
        //     }
        //     cout<<"\n";
        }

        string ans = "";
        q1.pop();
        while (!q1.empty())
        {
            ans += (q1.front() + '0');
            q1.pop();
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}