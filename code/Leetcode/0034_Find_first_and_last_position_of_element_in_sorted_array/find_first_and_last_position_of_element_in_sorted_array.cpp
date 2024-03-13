class Solution {
public:

    int lowerBound (vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        int mid = start + (end - start)/2;

        while(start <= end)
        {
            mid = start + (end - start/2);
            
            if(nums[mid] == target)
            {
                ans = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }

     int upperBound (vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        int mid = start + (end - start)/2;

        while(start <= end)
        {
            mid = start + (end - start/2);
            
            if(nums[mid] == target)
            {
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }

    
    vector<int> searchRange(vector<int>& nums, int target) {

        return {lowerBound(nums, target), upperBound(nums, target)};
        
    }
};
