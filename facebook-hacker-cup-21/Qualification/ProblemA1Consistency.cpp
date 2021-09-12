#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

void optimize()
{
    ios_base ::sync_with_stdio(false);
}

void setupFileIO(string fin = "data/consistency_chapter_1_input.txt", string fout = "data/A1output.txt")
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
    int mapper[30];
    int totalvowels = 0, mostVowels = 0;
    int totalCons = 0, mostCons = 0, strLength = s.size();

    memset(mapper, 0, sizeof(mapper));

    for (int i = 0; i < strLength; i++)
    {
        int index = s[i] - 'A';
        mapper[index]++;
        if (isVowel(s[i]))
        {
            mostVowels = max(mostVowels, mapper[index]);
            totalvowels++;
        }
        else
        {
            mostCons = max(mostCons, mapper[index]);
            totalCons++;
        }
    }

    int ans1 = totalCons + (totalvowels - mostVowels) * 2;
    int ans2 = totalvowels + (totalCons - mostCons) * 2;

    return min(ans1, ans2);
}

void solve()
{
    int ntc;
    cin >> ntc;

    for (int tc = 1; tc <= ntc; tc++)
    {
        string s;
        cin >> s;
        int seconds = getMinSeconds(s);
        cout << "Case #" << tc << ": " << seconds << "\n";
    }
}

int main()
{
    optimize();

    setupFileIO();

    solve();

    return 0;
}