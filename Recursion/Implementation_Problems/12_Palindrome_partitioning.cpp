
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    bool checkPalindrome(string str, int start, int end)
    {

        while (start <= end)
        {
            if (str[start++] != str[end--])
            {
                return false;
            }
        }

        return true;
    }

    void getSubstrings(int index, vector<string> list, vector<vector<string>> &ans, string s)
    {

        if (index == s.size())
        {
            ans.push_back(list);
            return;
        }

        for (int j = index; j < s.size(); j++)
        {
            if (checkPalindrome(s, index, j))
            {

                string subString = s.substr(index, j - index + 1);

                list.push_back(subString);
                getSubstrings(j + 1, list, ans, s);

                list.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {

        vector<string> list;
        vector<vector<string>> ans;

        getSubstrings(0, list, ans, s);

        return ans;
    }
};