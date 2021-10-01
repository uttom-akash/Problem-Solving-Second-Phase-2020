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

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void solve()
{

    int ntc;
    cin >> ntc;

    for (int tc = 0; tc < ntc; tc++)
    {
        int n;
        cin >> n;
        int a[100 + 5], sa[100 + 5];
        unordered_map<int, int> mapper;
        vector<pair<int, pair<int, int>>> ans;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sa[i] = a[i];
            mapper[a[i]]++;
        }

        sort(sa, sa + n);

        for (int i = 0; i < n; i++)
        {
            int index = upper_bound(sa, sa + n, a[i]) - sa;
            index -= mapper[a[i]]--;

            int shift = (i - index + n) % n;
        }
    }
}

int main()
{
    optimize();

    solve();

    return 0;
}