#include <stdio.h>
#include <vector>
using namespace std;

// (T.C - {O(N}, S.C - O(1))
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                five++;
            }
            else if (bills[i] == 10)
            {
                if (five == 0)
                    return false;

                five--;
                ten++;
            }
            else
            {
                if (five && ten)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }

        return true;
    }
};