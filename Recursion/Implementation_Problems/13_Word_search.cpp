
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    bool wordSearch(int index, int i, int j, string word, vector<vector<char>> &board)
    {

        if (index == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0';

        bool ans = wordSearch(index + 1, i - 1, j, word, board) || // Up
                   wordSearch(index + 1, i + 1, j, word, board) || // Down
                   wordSearch(index + 1, i, j - 1, word, board) || // Left
                   wordSearch(index + 1, i, j + 1, word, board);
        board[i][j] = temp;

        return ans;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (word[0] == board[i][j])
                {
                    if (wordSearch(0, i, j, word, board))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};