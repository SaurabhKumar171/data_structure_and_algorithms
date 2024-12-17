
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

class Solution
{
private:
    bool placingQueens(vector<string> board, int row, int col, int n)
    {
        int tempRow = row, tempCol = col;

        while (tempRow >= 0)
        {
            if (board[tempRow][tempCol] == 'Q')
                return false;

            tempRow--;
        }

        tempRow = row;
        tempCol = col;

        while (tempRow >= 0 && tempCol < n)
        {
            if (board[tempRow][tempCol] == 'Q')
                return false;

            tempRow--;
            tempCol++;
        }

        tempRow = row;
        tempCol = col;

        while (tempRow >= 0 && tempCol >= 0)
        {
            if (board[tempRow][tempCol] == 'Q')
                return false;

            tempRow--;
            tempCol--;
        }

        return true;
    }

private:
    void placeQueens(int row, vector<vector<string>> &ans, vector<string> board, int n)
    {

        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (placingQueens(board, row, col, n))
            {
                board[row][col] = 'Q';

                placeQueens(row + 1, ans, board, n);

                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // your code goes here
        vector<vector<string>> ans;
        vector<string> board;
        string str = "";

        for (int i = 0; i < n; i++)
        {
            str += ".";
        }

        for (int i = 0; i < n; i++)
        {
            board.push_back(str);
        }

        placeQueens(0, ans, board, n);

        return ans;
    }
};