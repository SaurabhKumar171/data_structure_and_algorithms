#include <stdio.h>
#include <vector>
using namespace std;

// (T.C - {O(NlogN) + O(N}, S.C - O(1))
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        long long currentWaitingTime = 0;
        long long waitTime = 0;

        sort(bt.begin(), bt.end());

        for (int i = 0; i < bt.size(); i++)
        {
            waitTime += currentWaitingTime;
            currentWaitingTime += bt[i];
        }

        return (waitTime / bt.size());
    }
};