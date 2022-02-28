#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    vector<int> adjList[5000 + 5];
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        map<string, int> mapper;
        for (int i = 0; i < wordList.size(); i++)
        {
            auto word = wordList[i];
            mapper[word] = i + 1;
        }

        if (!mapper[endWord])
            return 0;

        if (!mapper[beginWord])
        {
            wordList.push_back(beginWord);
            mapper[beginWord] = wordList.size();
        }

        int sz = wordList.size();
        int wordSz = beginWord.size();

        queue<int> bfs;
        int dist[sz + 5];
        memset(dist, -1, sizeof(dist));
        int start = mapper[beginWord] - 1;
        int end = mapper[endWord] - 1;
        bfs.push(start);
        dist[start] = 0;

        while (!bfs.empty())
        {
            int u = bfs.front();
            bfs.pop();

            if (u == end)
            {
                return dist[end] + 1;
            }

            auto uw = wordList[u];
            for (int pos = 0; pos < wordSz; pos++)
            {
                auto vw = uw;
                for (char a = 'a'; a <= 'z'; a++)
                {
                    if (uw[pos] == a)
                        continue;

                    vw[pos] = a;
                    if (mapper[vw])
                    {
                        int v = mapper[vw] - 1;
                        if (dist[v] == -1)
                        {
                            bfs.push(v);
                            dist[v] = dist[u] + 1;
                        }
                    }
                }
            }

         return dist[end] + 1;
    }

    // bool canGo(string a, string b)
    // {
    //     int sz = a.size(), diff = 0;
    //     for (size_t i = 0; i < sz; i++)
    //     {
    //         if (a[i] != b[i])
    //             diff++;
    //     }

    //     return diff == 1;
    // }

    // int bfs(int start, int end, int sz)
    // {

    //     queue<int> bfs;
    //     int dist[sz + 5];

    //     memset(dist, -1, sizeof(dist));

    //     bfs.push(start);
    //     dist[start] = 0;

    //     while (!bfs.empty())
    //     {
    //         int u = bfs.front();
    //         bfs.pop();

    //         if (u == end)
    //         {
    //             return dist[end] + 1;
    //         }

    //         for (auto v : adjList[u])
    //         {
    //             if (dist[v] == -1)
    //             {
    //                 bfs.push(v);
    //                 dist[v] = dist[u] + 1;
    //             }
    //         }
    //     }

    //     return dist[end] + 1;
    // }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<int> a()
    vector<string> v({"kinds", "taney", "mangy", "pimps", "belly", "liter", "cooks", "finny", "buddy", "hewer", "roves", "lusts", "toots", "fully", "acorn", "junes", "araby", "visas", "pyres", "siren", "limps", "paved", "marla", "tulsa", "foxes", "purls", "stats", "bidet", "milky", "payee", "horny", "tanks", "mints", "cindy", "forms", "files", "fucks", "dolts", "welts", "dykes", "riced", "rebel", "gulfs", "bully", "meets", "tidal", "surer", "gecko", "noyes", "rents", "aaron", "rafts", "roils", "sower", "dicey", "sties", "jamal", "bases", "locus", "gusts", "briar", "gills", "filly", "mixes", "fjord", "aggie", "tails", "funks", "freon", "roods", "links", "natal", "melds", "abide", "hardy", "lands", "unpin", "loges", "weest", "rices", "dicks", "gyros", "hands", "quoit", "hater", "rings", "loxed", "weeds", "coeds", "handy", "boxer", "jamar", "cokes", "earls", "tings", "haley", "tangy", "hinds", "cater", "mores", "lloyd", "bayes", "slice", "taker", "piped", "doses", "sides", "gorge", "sorta", "gavel", "lanes", "wrote", "haney", "monet", "mikes", "bared", "pelts", "fails", "curry", "waken", "jaded", "halos", "welds", "danes", "assad", "waded", "agree", "bents", "comet", "train", "crags", "fifes", "rared", "noons", "scums", "steep", "haler", "waxen", "carey", "gamay", "larry", "diver", "honer", "mandy", "poxed", "coded", "waned", "sades", "clair", "fared", "hangs", "sully", "tiled", "stoic", "docks", "cloth"});
    s.ladderLength("cater", "mangy", v);
    return 0;
}
