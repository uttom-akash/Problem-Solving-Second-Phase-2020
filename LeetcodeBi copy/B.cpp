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
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        map<string,int> counter;

        for (auto word : startWords)
        {
            sort(word.begin(),word.end());

            counter[word]++;
        }

        int ans=0;
        for (auto word : targetWords)
        {
            sort(word.begin(),word.end());
            int sz= word.size();

            for(int i=0;i<sz;i++){
                string s="";
                for(int j=0;j<sz;j++){
                    if(i==j)continue;
                    s+=word[j];
                }

                if(counter[s]>0){
                    counter[s]--;
                    ans++;
                    break;
                }
            }
        }
        

        return ans;
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