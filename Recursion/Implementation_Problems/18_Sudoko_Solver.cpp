class Solution {
private:
    bool solve(vector<vector<char> >& board){
        int N = 9;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == '.'){
                    for(int digit = 1; digit <= 9; digit++){
                        if(func(board, digit, i, j)){
                            board[i][j] = digit + '0';
                            bool val = solve(board);
                            if(val) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }            
        }

        return true;
    }

    bool func(vector<vector<char> >& board, int digit, int row, int col){
        int N = 9;

        int startRow = (row/3)*3;
        int startCol = (col/3)*3;

        digit = digit + '0';

        for(int i = 0; i < N; i++){
            if(board[i][col] == digit) return false;

            if(board[row][i] == digit) return false;

            if(board[startRow + (i/3)][startCol + (i%3)] == digit) return false;
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};