class Solution {
public:
    int helper(vector<int>& nums, int i, int *dp)
    {
        if(i >= nums.size())
        {
            return 0;
        }

        if(dp[i] != -1)
            return dp[i];

        int steal = nums[i] + helper(nums, i+2, dp);
        int skip = helper(nums, i+1, dp);

        return dp[i] = max(steal, skip);
    }

    int rob(vector<int>& nums) {

        int dp[101];

        memset(dp, -1, sizeof(dp));
        
        return helper(nums, 0, dp);

    }
};
