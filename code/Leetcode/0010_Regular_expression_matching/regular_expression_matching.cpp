class Solution {
public:
    int dp[20][20];

    bool dfs(string& s, string& p, int i, int j)
    {
        if(p.length() == j)
            return (s.length() == i);

        if(dp[i][j] != -1)
            return dp[i][j];

        bool match = false;
        
        if(i < s.length() && (s[i] == p[j] || p[j] == '.'))
            match = true;

        if(p[j+1] == '*')
        {
            bool not_take = dfs(s, p, i, j+2);
            bool take = match && dfs(s, p, i+1, j);

            return dp[i][j] = (not_take || take);
        }

        return dp[i][j] = match && dfs(s, p, i+1, j+1);
    }

    bool isMatch(string s, string p) {
        
        memset(dp, -1, sizeof(dp));

        return dfs(s, p, 0, 0);   
    }
};
