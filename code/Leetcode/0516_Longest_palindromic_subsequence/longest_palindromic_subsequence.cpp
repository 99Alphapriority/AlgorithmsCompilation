class Solution {
public:
    int dfs(string& s, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            dp[i][j] = 2 + dfs(s, i+1, j-1, dp);
        else
            dp[i][j] = max(dfs(s, i+1, j, dp), dfs(s, i, j-1, dp));

        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(s, 0, n-1, dp);
    }
};
