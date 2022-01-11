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

struct Plant
{
    int pt,gt;

    Plant(int p,int g){
        pt=p;
        gt=g;
    }
    bool operator<(const Plant &p)
    {
        if(gt>p.gt)
            return true;
        if(gt==p.gt && pt<p.pt)
            return true;
        
        return false;
    }
};

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int sz= plantTime.size();
        vector<Plant> plants;

        for (int i = 0; i < sz; i++)
        {
            plants.push_back(Plant(plantTime[i],growTime[i]));    
        }

        sort(plants.begin(),plants.end());

        int time=0,carry=0;
        for (int i = 0; i < sz; i++)
        {
            time+=plants[i].pt;

            if(carry>=plants[i].pt)carry-=plants[i].pt;
            else carry=0;

            carry=max(carry, plants[i].gt);
        }

        return time + carry;
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