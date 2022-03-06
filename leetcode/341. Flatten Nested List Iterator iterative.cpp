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
    stack<NestedInteger> states;

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        int sz = nestedList.size();

        for (int i = sz - 1; i >= 0; i--)
        {
            states.push(nestedList[i]);
        }
    }

    int next()
    {
        auto top = states.top();
        states.pop();

        return top.getInteger();
    }

    bool hasNext()
    {
        return doDFS();
    }

    bool doDFS()
    {

        while (!states.empty())
        {
            auto nestedInt = states.top();
            cout << "--\n";
            if (nestedInt.isInteger())
            {
                cout << nestedInt.getInteger() << "\n";
                return true;
            }

            states.pop();

            auto nestedList = nestedInt.getList();
            int sz = nestedList.size();

            for (int i = sz - 1; i >= 0; i--)
            {
                states.push(nestedList[i]);
            }
        }

        return false;
    }
};
