class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<bool>& visited)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                curr.push_back(nums[i]);
                dfs(nums, curr, ans, visited);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);

        dfs(nums, curr, ans, visited);

        return ans;


        
    }
};
