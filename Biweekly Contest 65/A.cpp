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
    bool checkAlmostEquivalent(string word1, string word2)
    {
        int freq[30];
        memset(freq, 0, sizeof(freq));

        for (auto c : word1)
        {
            freq[c - 'a']++;
        }

        for (auto c : word2)
        {
            freq[c - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (abs(freq[i]) > 3)
                return false;
        }

        return true;
    }
};

void solve()
{

   Solution s;
   s.checkAlmostEquivalent("abcdeef"
,"abaaacc");
}

int main()
{
    optimize();

    solve();

    return 0;
}