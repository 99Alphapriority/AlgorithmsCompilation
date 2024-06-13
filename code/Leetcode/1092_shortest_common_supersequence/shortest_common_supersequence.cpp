class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int i, j;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(i = 0; i < m+1; i++)
        {
            for(j = 0; j < n+1; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = i + j;
                }
                else
                {
                    if(s1[i-1] == s2[j-1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }

        string ans = "";
        i = m;
        j = n;

        while(i > 0 && j > 0)
        {
            if(s1[i-1] == s2[j-1])
            {
                i--;
                j--;
                ans += s1[i];
            }
            else
            {
                if(dp[i-1][j] < dp[i][j-1])
                {
                    i--;
                    ans += s1[i];
                }
                else
                {
                    j--;
                    ans += s2[j];
                }
            }
        }

        while(i > 0)
        {
            i--;
            ans += s1[i];
        }

        while(j > 0)
        {
            j--;
            ans += s2[j];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
