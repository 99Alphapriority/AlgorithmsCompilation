class Solution {
public:
    int n, m, s;
    int dp[101][101];
    
    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3)
    {
        int result;

        if(i == m && j == n && k == s)
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s3[k])
            result = dfs(i+1, j, k+1, s1, s2, s3);

        if(result)
            return dp[i][j] = result;

        if(s2[j] == s3[k])
            result = dfs(i, j+1, k+1, s1, s2, s3);

        return dp[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
    
        if(s3.length() != (s1.length() + s2.length()))
            return false;

        m = s1.length();
        n = s2.length();
        s = s3.length();

        memset(dp, -1, sizeof(dp));

        return dfs(0,0,0,s1,s2,s3);
    }
};
