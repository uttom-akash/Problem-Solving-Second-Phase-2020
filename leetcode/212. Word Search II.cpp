#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long
#define way4                               \
    (int[4][2])                            \
    {                                      \
        {0, 1}, {1, 0}, {0, -1}, { -1, 0 } \
    }

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

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    TrieNode()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
            {
                pCrawl->children[index] = new TrieNode();
            }

            pCrawl = pCrawl->children[index];
        }
    }

    bool search(string key)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;

            pCrawl = pCrawl->children[index];
        }

        return true;
    }

    ~Trie()
    {
        delete root;
    }
};

class Solution
{
private:
    Trie *trie;

public:
    Solution()
    {
        trie = new Trie();
    }

    void dfs(int ui, int uj, vector<vector<char>> &board, int n, int m)
    {
        stack<pair<pair<int, int>, string>> tracker;
        short visit[n][m];
        string word = "";

        memset(visit, 0, sizeof(visit));

        word = word + board[ui][uj];
        tracker.push({{ui, uj}, word});
        visit[ui][uj] = 1;

        while (!tracker.empty())
        {
            auto u = tracker.top();
            tracker.pop();
            word = u.second;
            bool stoppage = true;

            for (size_t i = 0; i < 4; i++)
            {
                auto vi = u.first.first + way4[i][0];
                auto vj = u.first.second + way4[i][1];

                if (visit[vi][vj])
                    continue;

                stoppage = false;
                visit[vi][vj] = 1;
                cout << u.second << " " << board[vi][vj] << "\n";
                tracker.push({{vi, vj}, word + board[vi][vj]});
            }

            if (stoppage)
            {
                cout << u.second << "\n";
                // trie->insert(u.second);
            }
        }

        cout << "\n";
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        int n = board.size();
        int m = board[0].size();

        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                dfs(i, j, board, n, m);
            }
        }

        return words;
    }
};

void solve()
{

    cout << "ok"
         << "\n";
    vector<vector<char>> board({{'a', 'b'}, {'c', 'd'}});
    vector<string> v({"akash"});
    Solution s;
    s.findWords(board, v);
}

int main()
{
    optimize();

    solve();

    return 0;
}
