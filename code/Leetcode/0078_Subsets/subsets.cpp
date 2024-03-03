class Solution {
public:

    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans)
    {
        ans.push_back(curr);

        for(int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            dfs(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        dfs(nums, 0, curr, ans);

        return ans;
        
    }
};
