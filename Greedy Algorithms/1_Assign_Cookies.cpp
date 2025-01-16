#include <stdio.h>
#include <vector>
using namespace std;

// (T.C - {O(N*log(N) + M*log(M) + O(M)}, S.C - O(1))
class Solution
{
public:
    int findMaximumCookieStudents(vector<int> &Student, vector<int> &Cookie)
    {
        int i = 0;
        int j = 0;

        int n = Student.size(), m = Cookie.size();

        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        while (i < n && j < m)
        {
            if (Cookie[j] >= Student[i])
            {
                i++;
            }
            j++;
        }

        return i;
    }
};