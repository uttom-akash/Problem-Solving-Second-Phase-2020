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

class Solution
{
private:
    long ab, bc, ca, abc;

public:
    int getUglies(int a, int b, int c, long mid)
    {
        int cnt = mid / a + mid / b + mid / c;
        cnt = cnt - mid / ab - mid / bc - mid / ca;
        cnt = cnt + mid / abc;
        return cnt;
    }

    long getLCM(long a, long b)
    {
        return a * b / __gcd(a, b);
    }

    int nthUglyNumber(int n, int a, int b, int c)
    {
        ab = getLCM(a, b);
        bc = getLCM(b, c);
        ca = getLCM(c, a);
        abc = getLCM(ab, c);

        int smallest = min(a, min(b, c));

        long lo = smallest, hi = smallest * n;
        while (lo < hi)
        {
            int mid = (hi + lo) >> 1;
            int totalElements = getUglies(a, b, c, mid);

            if (totalElements < n)
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
};

void solve()
{

    Solution s;
    s.nthUglyNumber(25,
                    2,
                    4,
                    7);
}

int main()
{
    optimize();

    solve();

    return 0;
}