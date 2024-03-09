class Solution {
public:
    int findMin(vector<int>& nums) {

        int size = nums.size();
        int min;
        int left = 0, right = size -1;
        int mid = left + (right - left)/2;

        min = nums[mid];

        if(nums[left] > nums[right])
        {
            if(min > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
            return nums[0];
        //printf("min: %d b4 loop\n",min);

        while(left <= right)
        {
            mid = left + (right - left) / 2;

            if(nums[mid] < min)
            {    
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            
            if(nums[mid] < min)
                min = nums[mid];
            
        }

        return min;
    }
};
