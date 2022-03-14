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
        int prevStockPrice = INT_MAX, profit = 0;

        for (auto price : prices)
        {
            if (prevStockPrice < price)
            {
                profit += (price - prevStockPrice);
            }

            prevStockPrice = price;
        }

        return profit;
    }
};