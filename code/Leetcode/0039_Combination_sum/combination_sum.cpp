class Solution {
public:

    void dfs(vector<int>& candidates, int target, int i, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(i >= candidates.size() || target < 0)
            return;

        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i, curr, ans);
        curr.pop_back();
        dfs(candidates, target, i + 1, curr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> curr;

        dfs(candidates, target, 0, curr, ans);

        return ans;
    }
};
