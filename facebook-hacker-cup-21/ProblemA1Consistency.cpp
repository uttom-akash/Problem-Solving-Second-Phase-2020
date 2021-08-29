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

char vowels[] = {'A', 'E', 'I', 'O', 'U'};

bool isVowel(char c)
{
    int vowelCnt = 5;
    for (int i = 0; i < vowelCnt; i++)
    {
        if (vowels[i] == c)
            return true;
    }

    return false;
}

int getMinSeconds(string s)
{
    int vowelsMapper[30], consonentMapper[30];
    int totalvowels = 0, mostVowels = 0;
    int totalCons = 0, mostCons = 0;

    memset(vowelsMapper, 0, sizeof(vowelsMapper));
    memset(consonentMapper, 0, sizeof(consonentMapper));

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'A';
        if (isVowel(s[i]))
        {

            vowelsMapper[index]++;
            mostVowels = max(mostVowels, vowelsMapper[index]);
            totalvowels++;
        }
        else
        {
            consonentMapper[index]++;
            mostCons = max(mostCons, consonentMapper[index]);
            totalCons++;
        }
    }

    int ans1 = totalCons + (totalvowels - mostVowels) * 2;
    int ans2 = totalvowels + (totalCons - mostCons) * 2;

    return min(ans1, ans2);
}

void solve()
{
    int tc;
    cin >> tc;

    for (int c = 0; c < tc; c++)
    {
        string s;
        cin >> s;
        cout << getMinSeconds(s) << "\n";
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}