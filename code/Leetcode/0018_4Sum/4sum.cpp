class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int size = nums.size();
        long long sum = 0;

        if(size < 4)
            return {};
        else if(size == 4)
        {
            sum = nums[0]; 
            sum += nums[1]; 
            sum += nums[2];
            sum += nums[3];

            if(sum == target)
                return {nums};
            else
                return {};
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < size; i++)
        {
            if(i > 0 && (nums[i] == nums[i-1]))
                continue;
            
            for(int j = i+1; j < (size-2); j++)
            {
                if(j > (i+1) && (nums[j] == nums[j-1]))
                    continue;

                int high = size - 1;
                int low = j + 1;

                while(low < high)
                {
                    sum = nums[i];
                    sum += nums[j];
                    sum += nums[low];
                    sum += nums[high];

                    if(sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        high--;
                        low++;

                        while((low < high) && (nums[high] == nums[high + 1]))
                            high--;
                        
                        while((low < high) && (nums[low] == nums[low - 1]))
                            low++;
                    }
                    else if(sum > target)
                    {
                        high--;
                    }
                    else if(sum < target)
                    {
                        low++;
                    }
                }
            }
        }

        return ans;
        
    }
};
