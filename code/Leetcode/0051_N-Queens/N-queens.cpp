class Solution {
public:
    bool inbound(int row, int col, int n)
    {
        if(row < 0 || col < 0 || row >= n || col >= n)
            return false;
        
        return true;
    }

    bool valid(int row, int col, vector<string> &curr, int n)
    {
        for(int k = 0; k < n; k++)
        {
            if(curr[k][col] == 'Q' || curr[row][col] == 'Q')
                return false;
        }

        for(int k = 0; k < n; k++)
        {
            if(inbound(row-k, col-k, n) && curr[row-k][col-k] == 'Q')
                return false;
            
            if(inbound(row-k, col+k, n) && curr[row-k][col+k] == 'Q')
                return false;

            if(inbound(row+k, col-k, n) && curr[row+k][col-k] == 'Q')
                return false;
            
            if(inbound(row+k, col+k, n) && curr[row+k][col+k] == 'Q')
                return false;
        }

        return true;
    }

    void helper(vector<vector<string>>& ans, vector<string>&curr, int n, int row)
    {
        if(row == n)
        {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(valid(row, i, curr, n))
            {
                curr[row][i] = 'Q';
                helper(ans, curr, n, row+1);
                curr[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> curr (n, string(n, '.'));

        helper(ans, curr, n, 0);

        return ans;
        
    }
};
