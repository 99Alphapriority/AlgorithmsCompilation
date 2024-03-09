class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int& currArea, int& maxArea)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || (0 == grid[i][j]))
            return;

        grid[i][j] = 0;
        currArea ++;
        

        dfs(grid, i - 1, j, m, n, currArea, maxArea);
        dfs(grid, i + 1, j, m, n, currArea, maxArea);
        dfs(grid, i, j - 1, m, n, currArea, maxArea);
        dfs(grid, i, j + 1, m, n, currArea, maxArea);

        maxArea = max(currArea, maxArea);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        int currArea = 0;
        int m = grid.size();
        int n = grid[0].size();


        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(1 == grid[i][j])
                {
                    currArea = 0;
                    dfs(grid, i, j, m, n, currArea, maxArea);
                }
            }
        }

        return maxArea;
    }
};
