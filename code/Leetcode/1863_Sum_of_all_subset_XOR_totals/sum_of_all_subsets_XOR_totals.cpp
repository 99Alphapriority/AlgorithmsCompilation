class Solution {
public:
    void helper(vector<int>& nums, vector<int>& arr, int i, vector<int>& ans, int n)
    {
        if(i >= n)
        {
            int xorAns = 0;
            for(auto &it:arr)
            {
                xorAns ^= it;
            }
            ans.push_back(xorAns);
            return;
        }

        arr.push_back(nums[i]);
        helper(nums, arr, i+1, ans, n);
        arr.pop_back();
        helper(nums, arr, i+1, ans, n);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> arr;

        if(n == 1)
            return nums[0];
        
        helper(nums, arr, 0, ans, n);

        return accumulate(ans.begin(), ans.end(), 0);
    }
};
