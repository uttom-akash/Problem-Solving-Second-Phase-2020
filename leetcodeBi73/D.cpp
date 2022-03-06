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

class BIT
{
private:
    int *BITree;
    int size;

public:
    BIT(int sz)
    {
        size = sz;
        BITree = new int[sz + 5];
        memset(BITree, 0, sizeof(int)*(sz+5));
    }

    int query(int index)
    {
        int sum = 0;
        index = index + 1;

        while (index > 0)
        {
            sum += BITree[index];

            // Move index to parent node in getSum View
            index -= index & (-index);
        }
        return sum;
    }

    void update(int index, int val)
    {
        index = index + 1;

        while (index <= size)
        {
            // Add 'val' to current node of BI Tree
            BITree[index] += val;

            index += index & (-index);
        }
    }
};

class Solution
{
private:
    int getInt(char c)
    {
        return c - 'a';
    }

public:
    int minMovesToMakePalindrome(string s)
    {
        int sz = s.size();
        vector<int> dict[30];

        for (int i = 0; i < sz; i++)
        {
            dict[getInt(s[i])].push_back(i);
        }

        int palindromePos[sz + 5];
        vector<pair<int, int>> pairs;

        for (int i = 0; i < 26; i++)
        {
            if (dict[i].size() == 0)
                continue;

            int noccurance = dict[i].size();

            if ((noccurance & 1))
            {
                palindromePos[dict[i][noccurance / 2]] = sz / 2;
            }
            
            for (int j = 0; j < noccurance / 2; j++)
            {
                    pairs.push_back({dict[i][j], dict[i][noccurance - j - 1]});
            }
            
        }

        sort(pairs.begin(), pairs.end());

        for (int i = 0; i < pairs.size(); i++)
        {
            // cout<<pairs[i].first<<" "<<pairs[i].second<<"\n";
            palindromePos[pairs[i].first] = i;
            palindromePos[pairs[i].second] = sz - i - 1;
        }
        // cout<<endl;

        BIT bit(sz);
        int cnt = 0;

        for (int i = sz - 1; i >= 0; i--)
        {
            // cout<<i<<" "<<palindromePos[i]<<"\n";
            cnt += bit.query(palindromePos[i] - 1);
            bit.update(palindromePos[i], 1);
        }

        return cnt;
    }
};

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}