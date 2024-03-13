class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return 1;
        
        int i = 0;
        int j = 1;

        while(j < n)
        {
            if(nums[i] == nums[j])
                j++;
            else
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
    }
};
