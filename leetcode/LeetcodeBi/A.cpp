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
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        map<string, int> freq1;
        map<string, int> freq2;

        for (auto word : words1)
        {
            freq1[word]++;
        }

        for (auto word : words2)
        {
            freq2[word]++;
        }

        int ans = 0;
        for (auto word : words1)
        {
            if (freq1[word] == 1 && freq2[word] == 1)
                ans++;
        }
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