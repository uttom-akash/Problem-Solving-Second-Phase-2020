class Solution
{
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int l = upper_bound(intervals.begin(), intervals.end(), newInterval, comp) - intervals.begin();
        cout << l << "\n";

        return intervals;
    }
};