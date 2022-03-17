#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

#define way4                               \
    (int[4][2])                            \
    {                                      \
        {0, 1}, {1, 0}, {0, -1}, { -1, 0 } \
    }

class Solution
{
    int visited[7][7];

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    memset(visited, -1, sizeof(visited));
                    if (doDfs(board, n, m, i, j, 1, word))
                        return true;
                }
            }
        }

        return false;
    }

    int doDfs(vector<vector<char>> &board, int n, int m, int sr, int sc, int pos, string word)
    {
        if (visited[sr][sc] != -1)
            return 0;

        cout << sr << " " << sc << " " << visited[sr][sc] << " " << pos << "\n";
        if (pos == word.size())
        {
            return 1;
        }

        visited[sr][sc] = 0;

        for (int i = 0; i < 4; i++)
        {
            int vr = sr + way4[i][0];
            int vc = sc + way4[i][1];

            if (vr < 0 || vr >= n || vc < 0 || vc >= m || board[vr][vc] != word[pos])
                continue;

            visited[sr][sc] |= doDfs(board, n, m, vr, vc, pos + 1, word);
            cout << sr << " " << sc << " " << visited[sr][sc] << " " << pos << "\n";
        }

        return visited[sr][sc];
    }
};
