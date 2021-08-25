#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int length = prices.size();
        int maxProfit = 0, smallest = prices[0];

        int i = 0;
        while (i < length)
        {
            maxProfit = max(maxProfit, prices[i] - smallest);
            smallest = min(smallest, prices[i]);
            i++;
        }

        return maxProfit;
    }
};

int main()
{

    // freopen("ethan_searches_for_a_string.txt","r",stdin);
    // freopen("ans.txt","w",stdout);

    ios_base ::sync_with_stdio(false);

    vector<int> nums({1,2});
    auto sol = new Solution();
    cout<<sol->maxProfit(nums)<<"\n";
    
    return 0;
}