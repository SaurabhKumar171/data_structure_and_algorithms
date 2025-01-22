#include <vector>
using namespace std;

// Using 2D Array
// (T.C - {O(NlogN) + O(N)}, S.C - {O(1)})

class Solution
{
private:
    static bool comparator(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &Intervals)
    {
        sort(Intervals.begin(), Intervals.end(), comparator);

        int n = Intervals.size();
        int currentEndTime = Intervals[0][1];
        int removeCnt = 0;

        for (int i = 1; i < n; i++)
        {
            if (Intervals[i][0] < currentEndTime)
            {
                removeCnt++;
            }
            else
            {
                currentEndTime = Intervals[i][1];
            }
        }

        return removeCnt;
    }
};