void checkIslands(char** grid, int i, int j, int m, int n)
{

    if((i >= 0) && (j >= 0) && (i < m) && (j < n) && (grid[i][j] == '1'))
    {
        grid[i][j] = '0';
        checkIslands(grid, i + 1, j, m, n);
        checkIslands(grid, i - 1, j, m ,n);
        checkIslands(grid, i, j + 1, m, n);
        checkIslands(grid, i, j - 1, m, n);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {

    int i = 0, j = 0;
    int ans = 0;

    for(i = 0; i < gridSize; i++)
    {
        for(j = 0; j < (*gridColSize); j++)
        {
            if(grid[i][j] == '1')
            {
                checkIslands(grid, i, j, gridSize, (*gridColSize));
                ans++;
            }
        }
    }

    return ans;
}
