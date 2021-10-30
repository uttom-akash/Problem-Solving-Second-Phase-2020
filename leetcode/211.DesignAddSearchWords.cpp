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

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{

public:
    TrieNode *root;
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

        pCrawl->isEndOfWord = true;
    }

    bool search(TrieNode *crawl, string key, int index)
    {
        if (index == key.size())
            return (crawl->isEndOfWord);

        bool way = false;

        if (key[index] != '.')
        {
            auto childIndex = key[index] - 'a';
            if (crawl->children[childIndex] == nullptr)
            {
                return false;
            }

            way |= search(crawl->children[childIndex], key, index + 1);
        }
        else
        {
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (crawl->children[i] != nullptr)
                {
                    way |= search(crawl->children[i], key, index + 1);
                }
            }
        }

        return way;
    }

    ~Trie()
    {
        delete root;
    }
};

class WordDictionary
{
private:
    Trie *trie;

public:
    WordDictionary()
    {
        trie = new Trie();
    }

    void addWord(string word)
    {
        trie->insert(word);
    }

    bool search(string word)
    {
        return trie->search(trie->root, word, 0);
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

    int a[3];
    for (int i = 0; scanf("%d", &a[i]); i++)
    {
        cout << a[i] << '\n';
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}