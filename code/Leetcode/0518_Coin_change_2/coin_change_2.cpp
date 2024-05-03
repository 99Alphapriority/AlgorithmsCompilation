class Solution {
public:
    int dp[301][5001];
    int dfs(int amount, vector<int>& coins, int i, int sum)
    {
        if(amount == sum)
            return 1;

        if(amount < sum)
            return 0;

        if(i == coins.size())
            return 0;

        if(dp[i][sum] != -1)
            return dp[i][sum];

        dp[i][sum] = dfs(amount, coins, i, sum + coins[i]) + dfs(amount, coins, i + 1, sum);

        return dp[i][sum];

    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return dfs(amount, coins, 0, 0);
    }
};
