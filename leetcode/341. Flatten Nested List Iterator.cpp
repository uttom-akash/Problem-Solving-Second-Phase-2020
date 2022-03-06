#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    vector<int> flattenList;
    int index;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        index = 0;
        doDFS(nestedList);
    }

    int next()
    {
        return flattenList[index++];
    }

    bool hasNext()
    {
        if (index < flattenList.size())
            return true;

        return false;
    }

    void doDFS(vector<NestedInteger> &nestedList)
    {

        for (auto nestedInt : nestedList)
        {
            if (nestedInt.isInteger())
            {
                flattenList.push_back(nestedInt.getInteger());
            }
            else
            {
                auto list = nestedInt.getList();
                doDFS(list);
            }
        }
    }
};
