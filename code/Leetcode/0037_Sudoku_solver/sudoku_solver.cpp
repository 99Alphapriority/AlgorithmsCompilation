class Solution {
public:
    
    bool isValid(char num, int i, int j, vector<vector<char>>& board, int n)
    {
        
        for(int k = 0; k < n; k++)
        {
            if(num == board[i][k])
                return false;
            
            if(num == board[k][j])
                return false;
            
            if (num == board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3]) 
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int n)
    {
        int row, col;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(board[row][col] == '.')
                {
                    for(char num = '1'; num <= n + '0'; num++)
                    {
                        if(isValid(num, row, col, board, n))
                        {
                            board[row][col] = num;
                            if(solve(board, n))
                                return true;
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        int n = board.size();

        solve(board, n);
    }
};
