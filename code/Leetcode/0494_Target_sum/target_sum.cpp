class Solution {
public:
    map<pair<int, int>, int> dp;

    int dfs(vector<int>& nums,int target, int i, int sum)
    {

        if(i == nums.size())
            return sum == target ? 1 : 0;

        if(dp.find({i, sum}) != dp.end())
            return dp[{i, sum}];
        
        dp[{i, sum}] = dfs(nums, target, i + 1, sum + nums[i]) + 
                    dfs(nums, target, i + 1, sum - nums[i]);
    
        return dp[{i, sum}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }
};
