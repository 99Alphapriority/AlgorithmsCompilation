class Solution {
public:
    int checkRows(vector<vector<char>>& board)
    {
        int rows = board.size();
        int columns = board[0].size();

        for(int i = 0; i<columns; i++)
        {
            map<int, int> mp;
            for(int j = 0; j<rows; j++)
            {
                mp[board[j][i]]++;

                if((1 < mp[board[j][i]]) && (board[j][i] != '.'))
                    return 1;
            }
        }

        return 0;
    }

    int checkColumns(vector<vector<char>>& board)
    {
        int columns = board[0].size();
        int rows = board.size();

        for(int i = 0; i< rows; i++)
        {
            map<int, int> mp;
            for(int j = 0; j<columns; j++)
            {
                mp[board[i][j]]++;

                if((1 < mp[board[i][j]]) && (board[i][j] != '.'))
                    return 1;
            }
        }

        return 0;
    }

    int checkMatrices(vector<vector<char>>& board)
    {
        int columns = board[0].size();
        int rows = board.size();

        map<int, map<int,int>> mp;

        int k = 0; //matrix number 0-8

        for(int i = 0; i < rows; i++)
        {
            if(i < 3)
                k = 0;
            else if(i < 6)
                k = 3;
            else
                k = 6;

            for(int j = 0; j<columns; j++)
            {
                if((j == 3) || (j == 6))
                    k += 1;

                mp[k][board[i][j]]++;

                if((1 < mp[k][board[i][j]]) && (board[i][j] != '.'))
                    return 1;
            }
        }
        
        return 0;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        if(checkRows(board))
            return false;
        
        if(checkColumns(board))
            return false;
        
        if(checkMatrices(board))
            return false;
        
        return true;
        
    }
};
