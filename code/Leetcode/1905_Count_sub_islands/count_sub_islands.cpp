class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int m, int n, bool &flag)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0)
            return;

        if(grid1[i][j] == 0 && grid2[i][j] == 1)
        {
            flag = false;
            return;
        }
        
        
        grid2[i][j] = 0;

        dfs(grid1, grid2, i - 1, j, m, n, flag);
        dfs(grid1, grid2, i + 1, j, m, n, flag);
        dfs(grid1, grid2, i, j - 1, m, n, flag);
        dfs(grid1, grid2, i, j + 1, m, n, flag);
        
        return;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int count = 0;
        int m = grid1.size();
        int n = grid1[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid2[i][j] == 1)
                {
                    bool flag = true;

                    dfs(grid1, grid2, i, j, m, n, flag);

                    if(flag)
                        count++;
                }
            }
        }

        
        return count;
    }
};
