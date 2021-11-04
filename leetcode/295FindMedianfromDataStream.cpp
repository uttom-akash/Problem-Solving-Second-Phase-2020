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

class MedianFinder
{
private:
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        right.push(num);

        if (left.size() <= right.size())
        {
            left.push(right.top());
            right.pop();
        }

        if (left.size() > 0 && right.size() > 0 && left.top() > right.top())
        {
            left.push(right.top());
            right.push(left.top());
            left.pop(), right.pop();
        }
    }

    double findMedian()
    {
        double median = left.top();
        auto sz = left.size() + right.size();

        if (!(sz & 1))
        {
            median = (median + right.top()) / (double)2;
        }

        return median;
    }
};

void solve()
{
    priority_queue<int, vector<int>, greater<int>> nums;
    nums.push(1);

    multiset<int>::iterator it;

    nums.push(2);
    nums.push(-1);
    nums.push(4);

    cout << nums.top() << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}