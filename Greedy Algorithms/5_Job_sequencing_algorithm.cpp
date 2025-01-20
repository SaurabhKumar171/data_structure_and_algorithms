#include <vector>
using namespace std;

// Using 2D Array
// (T.C - {O(NlogN) + O(N^2)}, S.C - O(N))
class Solution
{
public:
    vector<int> JobScheduling(vector<vector<int>> &Jobs)
    {

        sort(Jobs.begin(), Jobs.end(), [](const vector<int> nums1, const vector<int> nums2)
             { return nums1[2] > nums2[2]; });

        int row = Jobs.size();

        vector<int> storeJobProfit(row + 1, -1);

        int maxProfit = 0;
        int jobCnt = 0;

        for (int i = 0; i < row; i++)
        {
            int deadline = Jobs[i][1];

            if (storeJobProfit[deadline] == -1)
            {
                storeJobProfit[deadline] = Jobs[i][2];
                maxProfit += Jobs[i][2];
                jobCnt++;
            }
            else
            {
                deadline--;
                while (deadline != 0 && storeJobProfit[deadline] != -1)
                {
                    deadline--;
                }
                if (deadline != 0)
                {
                    storeJobProfit[deadline] = Jobs[i][2];
                    maxProfit += Jobs[i][2];
                    jobCnt++;
                }
            }
        }

        return {jobCnt, maxProfit};
    }
};