class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        long long ans = nums[0];
        long long avg = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            avg += nums[i];
            ans = max(ans, (avg+i)/(i+1));
        }
        return ans;
    }
};
