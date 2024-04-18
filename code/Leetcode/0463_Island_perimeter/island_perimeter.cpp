class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j, int& ans)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j>= grid[0].size() || grid[i][j] == 0)
            return true;

        if(grid[i][j] == -1)
            return false;

        grid[i][j] = -1;

        ans += dfs(grid, i - 1, j, ans);
        ans += dfs(grid, i + 1, j, ans);
        ans += dfs(grid, i, j - 1, ans);
        ans += dfs(grid, i, j + 1, ans);

        return false;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int ans = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(1 == grid[i][j])
                    dfs(grid, i, j, ans);
            }
        }

        return ans;
    }
};
