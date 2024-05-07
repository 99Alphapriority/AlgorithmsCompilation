class Solution {
public:
    int dfs(vector<int>& prices, int i, int state, vector<vector<int>>& dp)
    {
        if(i >= prices.size())
            return 0;

        if(dp[i][state] != -1)
            return dp[i][state];

        int buy, cooldown, sell;

        cooldown = dfs(prices, i + 1, state, dp);

        if(state)
        {
            sell = dfs(prices, i + 2, !state, dp) + prices[i];
            dp[i][state] = max(sell, cooldown);
        }
        else
        {
            buy = dfs(prices, i + 1, !state, dp) - prices[i];
            dp[i][state] = max(buy, cooldown);
        }

        return dp[i][state];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if(n == 1)
            return 0;

        vector<vector<int>> dp (n, vector<int> (2, -1));

        //0 -> buying
        //1 -> selling

        return dfs(prices, 0, 0, dp);
    }
};
