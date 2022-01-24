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

class TrieNode
{
    TrieNode *children[ALPHABET_SIZE] = {nullptr};
    bool isEndOfWord;

    int getIndex(char ch)
    {
        return ch - 'a';
    }

    bool doesExist(char ch)
    {
        return children[getIndex(ch)] != nullptr;
    }

    TrieNode *getNext(char ch)
    {
        return children[getIndex(ch)];
    }

    TrieNode *addNext(char ch)
    {
        if (!doesExist(ch))
            children[getIndex(ch)] = new TrieNode();

        return children[getIndex(ch)];
    }

public:
    void insert(string key)
    {
        TrieNode *pCrawl = this;

        int length = key.length();
        for (int i = 0; i < length; i++)
        {
            pCrawl = pCrawl->addNext(key[i]);
        }
        pCrawl->isEndOfWord = true;
    }

    bool search(string key)
    {
        struct TrieNode *pCrawl = this;
        int length = key.size();
        for (int i = 0; i < length; i++)
        {
            if (!pCrawl->doesExist(key[i]))
                return false;

            pCrawl = pCrawl->getNext(key[i]);

            if (pCrawl->isEndOfWord)
                return pCrawl->isEndOfWord;
        }

        return pCrawl->isEndOfWord;
    }
};

class StreamChecker
{
private:
    TrieNode trie;
    string streams;
    int mxLength;

public:
    StreamChecker(vector<string> &words)
    {
        streams = "";
        for (auto word : words)
        {
            reverse(word.begin(), word.end());
            trie.insert(word);
            mxLength = max(mxLength, (int)word.size());
        }
    }

    bool query(char letter)
    {
        streams = letter + streams.substr(0, mxLength);

        return trie.search(streams);
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