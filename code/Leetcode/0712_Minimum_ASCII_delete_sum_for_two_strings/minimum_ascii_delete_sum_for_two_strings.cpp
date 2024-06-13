class Solution {
public:
    int dp[1001][1001];
    int m, n;

    int dfs(string &s1, string& s2, int i, int j)
    {
        if(i == m && j == n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i >= m)
        {
            return dp[i][j] = s2[j] + dfs(s1, s2, i, j+1);
        }
        else if(j >= n)
        {
            return dp[i][j] = s1[i] + dfs(s1, s2, i+1, j);
        }

        if(s1[i] == s2[j])
            return dp[i][j] = dfs(s1, s2, i+1, j+1);

        int left = s1[i] + dfs(s1, s2, i+1, j);
        int right = s2[j] + dfs(s1, s2, i, j+1);

        return dp[i][j] = min(left, right);        
    }

    int minimumDeleteSum(string s1, string s2) {

        if(s1 == s2)
            return 0;
        
        memset(dp, -1, sizeof(dp));
        
        m = s1.length();
        n = s2.length();

        return dfs(s1, s2, 0, 0);
    }
};
