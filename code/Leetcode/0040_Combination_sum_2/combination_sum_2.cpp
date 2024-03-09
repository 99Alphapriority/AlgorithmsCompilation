class Solution {
public:
    void dfs(vector<int>& candidates, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(sum == target)
        {
            ans.push_back(curr);
            return;
        }

        if(sum > target)
            return; 

        for(int i = start; i < candidates.size(); i++)
        {
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            
            curr.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, 0, 0, curr, ans);

        return ans;
    }
};
