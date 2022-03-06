#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class SegmentTree
{

private:
    int *nodes;

    int getMid(int lo, int hi) { return lo + (hi - lo) / 2; }
    int getLeft(int root) { return 2 * root + 1; }
    int getRight(int root) { return 2 * root + 2; }
    int getNodeValue(int left, int right) { return max(left, right); }

public:
    SegmentTree(int arr[], int n)
    {
        // Height of segment tree
        int x = (int)(ceil(log2(n)));

        // Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;

        nodes = new int[max_size];

        buildSegmentTree(arr, 0, n - 1, 0);
    }

    int buildSegmentTree(int arr[], int lo, int hi, int nodeIndex)
    {
        if (lo == hi)
        {
            nodes[nodeIndex] = arr[lo];
            return nodes[nodeIndex];
        }

        int mid = getMid(lo, hi);
        nodes[nodeIndex] = getNodeValue(buildSegmentTree(arr, lo, mid, getLeft(nodeIndex)),
                                        buildSegmentTree(arr, mid + 1, hi, getRight(nodeIndex)));
        return nodes[nodeIndex];
    }

    int query(int lo, int hi, int queryLo, int queryHi, int nodeIndex)
    {
        if (queryLo <= lo && hi <= queryHi)
            return nodes[nodeIndex];

        if (hi < queryLo || queryHi < lo)
            return INT_MIN;

        int mid = getMid(lo, hi);

        return getNodeValue(query(lo, mid, queryLo, queryHi, getLeft(nodeIndex)),
                            query(mid + 1, hi, queryLo, queryHi, getRight(nodeIndex)));
    }

    int update(int lo, int hi, int i, int newVal, int nodeIndex)
    {
        if (lo == hi)
        {
            nodes[nodeIndex] = newVal;
            return nodes[nodeIndex];
        }

        if (i < lo || i > hi)
            return INT_MIN;

        int mid = getMid(lo, hi);
        nodes[nodeIndex] = getNodeValue(update(lo, mid, i, newVal, getLeft(nodeIndex)),
                                        update(mid + 1, hi, i, newVal, getRight(nodeIndex)));

        return nodes[nodeIndex];
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int sz = nums.size();
        SegmentTree st(nums.data(), sz);
        vector<int> ans;

        for (int i = 0; i + k - 1 < sz; i++)
        {
            int j = i + k - 1;

            auto ia = st.query(0, sz - 1, i, j, 0);

            ans.push_back(ia);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v({1, 3, -1, -3, 5, 3, 6, 7});
    Solution s;
    s.maxSlidingWindow(v, 3);
    return 0;
}
