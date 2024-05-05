class Solution {
public:
    int dp[201][201];
    int n, m;

    int dfs(vector<vector<int>>& matrix, int i, int j, int prev)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prev)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int result = 1;

        result = max(result, 1 + dfs(matrix, i - 1, j, matrix[i][j]));
        result = max(result, 1 + dfs(matrix, i + 1, j, matrix[i][j]));
        result = max(result, 1 + dfs(matrix, i, j - 1, matrix[i][j]));
        result = max(result, 1 + dfs(matrix, i, j + 1, matrix[i][j]));

        return dp[i][j] = result;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        memset(dp, -1, sizeof(dp));
        m = matrix.size();
        n = matrix[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans = max(ans, dfs(matrix, i, j, -1));
            }
        }

        return ans;

    }
};
