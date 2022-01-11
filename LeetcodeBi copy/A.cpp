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

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for (int i = 0; i < n; i++)
        {
            bool decs = check(i,n,matrix);
            if(!decs){
                return false;
            }
        }
        return true;
    }

    bool check(int r,int n, vector<vector<int>>& matrix){
        
        for(int num=1;num<=n;num++){
            bool rowOk=false,colOk=false;
            for (int i = 0; i < n; i++)
            {
                 if(matrix[r][i]==num){
                     rowOk=true;
                 } 

                 if(matrix[i][r]==num){
                     colOk=true;
                 }
            }

            if(!rowOk || !colOk){
                return false;
            }
        }
        
        return true;
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