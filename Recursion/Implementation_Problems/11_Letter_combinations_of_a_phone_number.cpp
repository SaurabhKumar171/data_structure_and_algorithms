
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    void func(int index, vector<string> &combos, vector<string> &ans, string digits, string s)
    {

        if (digits.size() == 0)
            return;

        if (index == digits.size())
        {
            ans.push_back(s);
            return;
        }

        int number = digits[index] - '0';

        for (int i = 0; i < combos[number].size(); i++)
        {
            func(index + 1, combos, ans, digits, s + combos[number][i]);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> combos = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string s;

        func(0, combos, ans, digits, s);

        return ans;
    }
};