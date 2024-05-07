class Solution {
public:
    int dfs(vector<int>& nums, vector<vector<int>>& dp, int left, int right)
    {
        if(right - left < 0)
            return 0;

        if(dp[left][right] > 0)
            return dp[left][right];

        int ans = 0;

        for(int i = left; i <= right; i++)
        {
            int curr = nums[left-1] * nums[i] * nums[right+1];
            int remaining = dfs(nums, dp, left, i - 1) + dfs(nums, dp, i + 1, right);
            ans = max(ans, curr + remaining);
        }

        dp[left][right] = ans;
        return ans;
    }

    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        return dfs(nums, dp, 1, n - 2);
        
    }
};
