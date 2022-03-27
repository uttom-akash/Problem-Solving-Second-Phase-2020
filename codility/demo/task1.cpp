#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

int solution(vector<int> &A)
{
    int sz = A.size();

    for (int i = 0; i < sz; i++)
    {
        while (A[i] > 0 && A[i] <= sz && A[i] != A[A[i] - 1])
        {
            swap(A[i], A[A[i] - 1]);
        }
    }

    for (int i = 0; i < sz; i++)
    {
        if (A[i] != i + 1)
            return i + 1;
    }

    return sz + 1;
}
