#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
private:
    short getShort(char c)
    {
        if (c >= '1' and c <= '9')
            return c - '0';

        return 0;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            vector<char> col, subs;
            for (int j = 0; j < 9; j++)
            {
                col.push_back(board[j][i]);
            }

            auto row = (i / 3) * 3, colum = (i * 3) % 9;
            for (int j = row; j < row + 3; j++)
            {
                for (int k = colum; k < colum + 3; k++)
                {
                    subs.push_back(board[j][k]);
                }
            }

            if (!check(board[i].data()) || !check(col.data()) || !check(subs.data()))
            {
                return false;
            }
        }

        return true;
    }


    bool check(char a[])
    {
        short mp[11];
        memset(mp, 0, sizeof(mp));

        for (int i = 0; i < 9; i++)
        {
            mp[getShort(a[i])]++;
        }


        for (int i = 1; i < 10; i++)
        {
            if (mp[i] > 1)
            {
                return false;
            }
        }

        return true;
    }
};