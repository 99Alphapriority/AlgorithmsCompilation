class Solution {
public:
    vector<int> leftProduct(vector<int>& nums, int& size)
    {
        vector<int> ans(size);
        ans[0] = 1;
        ans[1] = nums[0];
        int i = 0;

        for(int i = 2; i<size; i++)
        {
            ans[i] = ans[i-1] * nums[i-1];   
        }
        return ans;
    }

    vector<int> rightProduct(vector<int>& nums, int& size)
    {
        vector<int> ans(size);
        ans[size-1] = 1;
        ans[size-2] = nums[size-1];
        int i = 0;

        for(int i = size - 3; i>=0; i--)
        {
            ans[i] = ans[i+1] * nums[i+1];
        }
        return ans;
    }

    vector<int> productExceptSelf(vector<int>& nums) {

        
        int size = nums.size();
        vector<int> ans(size);

        vector<int> left = leftProduct(nums, size);
        vector<int> right = rightProduct(nums, size);

        for(int i = 0; i< size; i++)
        {
            ans[i] = left[i] * right[i];
        }

        return ans;

    }
};
