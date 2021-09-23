#include <bits/stdc++.h>

using namespace std;

void ok()
{
    int a[] = {1, 2, 3};
    auto comp = [](const int &i1, const int &i2)
    { return i1 < i2; };
    sort(a, a + 3, comp);
}