class Solution {
public:

    int search(vector<int>& nums, int target) {
        
        int size = nums.size();

        if(size == 1)
        {
            if(nums[0] == target)
                return 0;
            return -1;
        }

        int start = 0;
        int end = size - 1;

        while(start <= end)
        {
            int mid = (int)start + (end - start) / 2;
            printf("mid %d\n",mid);

            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > target)
            {
                end = mid - 1;    
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
        }

        return -1;
    }
};
