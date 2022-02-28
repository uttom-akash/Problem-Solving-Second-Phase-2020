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


struct B{
    int b;
    int p;
    B(int p1,int b1){
        b=b1,
        p=p1;
    }

    bool operator<(const B &a)
    {
        if(p<a.p)
            return true;
        if(b>a.b)
            return true;
    }
};

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<B>it;
        for (auto i : items)
        {
            it.push_back(B(i[0],i[1]));
        }
        
        sort(it.begin(),it.end());
        vector<int> ans;

        for (auto q : queries)
        {
            int index = upper_bound(it.begin(),it.end(),B(q,INT_MAX))-it.begin();
            index--;
            if(index<0)
                ans.push_back(0);
            else 
                ans.push_back(it[index].b);
        }
        
        return ans;
    }
};

void solve()
{

    ll n;
    cin >> n;
    ll ans = 0;

    for (int i = 1; i * i * i <= n; i++)
    {
        if (n % i != 0)
        {
            continue;
        }

        for (int j = i; i * j * j <= n; j++)
        {
            if (n % (1LL * i * j) != 0)
            {
                continue;
            }

            for (int k = j; i * j * k <= n; k++)
            {
                if (n % (1LL * i * j * k) != 0)
                {
                    continue;
                }

                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}