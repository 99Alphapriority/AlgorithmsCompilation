class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& curr, vector<int>& ans, int i, int n)
    {
        if(i >= n)
        {
            int orAns = 0;

            for(auto &it: curr)
            {
                orAns |= it;
            }
            ans.push_back(orAns);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, curr, ans, i + 1, n);
        curr.pop_back();
        dfs(nums, curr, ans, i + 1, n);
    }
    int countMaxOrSubsets(vector<int>& nums) {

        int n = nums.size();
        int count = 0;
        vector<int> ans;
        vector<int> curr;

        dfs(nums, curr, ans, 0, n);

        sort(ans.begin(), ans.end());

        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] == ans[ans.size() - 1])
                count++;
        }

        return count;
        
    }
};
