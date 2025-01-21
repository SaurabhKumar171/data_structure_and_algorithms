#include <stdio.h>
#include <vector>
using namespace std;

// (T.C - {O(N + N logN)}, S.C - O(N))
class Solution
{
private:
    static bool comparator(const pair<int, int> &a, const pair<int, int> &b)
    {
        // Sort by end time in ascending order
        return a.second < b.second;
    }

public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();

        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++)
        {
            meetings.push_back({start[i], end[i]});
        }

        sort(meetings.begin(), meetings.end(), comparator);

        int limit = meetings[0].second;
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (meetings[i].first > limit)
            {
                limit = meetings[i].second;
                count++;
            }
        }

        return count;
    }
};