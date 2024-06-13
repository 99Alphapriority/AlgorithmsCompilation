class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> arr (3, 0);

        for(int i = 0; i < nums.size(); i++)
            arr[nums[i]]++;

        for(int i = 0; i < nums.size(); i++)
        {
            if(arr[0] > 0)
            {
                nums[i] = 0;
                arr[0]--;
            }    
            else if(arr[1] > 0)
            {
                nums[i] = 1;
                arr[1]--;
            }
            else
            {
                nums[i] = 2;
                arr[2]--;
            }
        }        
    }
};
