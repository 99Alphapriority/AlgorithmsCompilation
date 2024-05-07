class Solution {
public:
    int dp[1000][1000];

    int dfs(string& s, string& t, int i, int j)
    {
        if(j == t.size())
            return 1;

        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j])
            dp[i][j] = dfs(s, t, i+1, j+1) + dfs(s, t, i+1, j);
        else
            dp[i][j] = dfs(s, t, i+1, j);

        return dp[i][j];
    }

    int numDistinct(string s, string t) {

        memset(dp, -1, sizeof(dp));

        return dfs(s, t, 0, 0);    
    }
};
