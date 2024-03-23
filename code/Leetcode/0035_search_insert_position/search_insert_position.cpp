class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;
        int mid = -1;

        if(target > nums[end])
            return end+1;

        while(start <= end)
        {
            mid = start + (end -start) / 2;

            if(nums[mid] == target)
                return mid;
            
            if(target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }
};
