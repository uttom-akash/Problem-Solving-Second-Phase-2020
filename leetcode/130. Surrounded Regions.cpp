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
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            eliminateFromBoundary(board, n, m, i, 0);
            eliminateFromBoundary(board, n, m, i, m - 1);
        }

        for (int j = 0; j < m; j++)
        {
            eliminateFromBoundary(board, n, m, 0, j);
            eliminateFromBoundary(board, n, m, n - 1, j);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void eliminateFromBoundary(vector<vector<char>> &board, int n, int m, int sr, int sc)
    {
        if (board[sr][sc] != 'O')
            return;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        board[sr][sc] = '#';

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                pair<int, int> v;
                v.first = u.first + way4[i][0];
                v.second = u.second + way4[i][1];

                if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                {
                    continue;
                }

                if (board[v.first][v.second] == 'O')
                {
                    board[v.first][v.second] = '#';
                    q.push(v);
                }
            }
        }
    }
};

class Solution2
{
    bool visited[205][205];

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' and !visited[i][j] and isSurrounded(board, n, m, i, j))
                {
                    capture(board, n, m, i, j);
                }
            }
        }
    }

    bool isSurrounded(vector<vector<char>> &board, int n, int m, int sr, int sc)
    {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                pair<int, int> v;
                v.first = u.first + way4[i][0];
                v.second = u.second + way4[i][1];

                if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                {
                    return false;
                }

                if (!visited[v.first][v.second] and board[v.first][v.second] == 'O')
                {
                    visited[v.first][v.second] = true;
                    q.push(v);
                }
            }
        }

        return true;
    }

    void capture(vector<vector<char>> &board, int n, int m, int sr, int sc)
    {
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                pair<int, int> v;
                v.first = u.first + way4[i][0];
                v.second = u.second + way4[i][1];

                if (board[v.first][v.second] == 'O')
                {
                    board[v.first][v.second] = 'X';
                    q.push(v);
                }
            }
        }
    }
};