#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n != 0 && (n & n - 1) == 0;
    }
};