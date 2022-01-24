#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        int ans = 0;
        vector<int> number = getNumber(n);
        vector<int> digitList = getDigits(digits);
        int sz = number.size();
        int dsz = digitList.size();

        for (int i = 0; i < sz; i++)
        {
            int uindex = upper_bound(digitList.begin(), digitList.end(), number[i]) - digitList.begin();
            int lindex = lower_bound(digitList.begin(), digitList.end(), number[i]) - digitList.begin();

            int temp = (i == 0 ? 1 : ans);
            ans = lindex * pow(dsz, i);           // for every digits less than number[i], we can place any digits in the right side
            ans = ans + temp * (uindex - lindex); // for every digits equal number[i], we can place only the calculated ans before because there we calculated less than and equal
        }
        // we calculated ans for 0 the position
        // now we will calculate ans for the cases where we can place zero in left side.

        for (int i = 1; i < sz; i++)
        {
            ans += pow(dsz, i); // we are placeing i zero left side here
        }

        return ans;
    }

    vector<int> getNumber(int n)
    {
        vector<int> number;
        while (n)
        {
            number.push_back(n % 10);
            n /= 10;
        }

        return number;
    }

    vector<int> getDigits(vector<string> &digits)
    {
        vector<int> v;

        for (auto num : digits)
        {
            v.push_back(stoi(num));
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;
    vector<string> v({"1", "2", "3", "4", "6", "7", "9"});
    s.atMostNGivenDigitSet(v, 333);
    return 0;
}
