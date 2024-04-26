class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, count = 0, last = 0;
        int n = nums.size();

        for(int i = 0; i < n - 1; i++)
        {
            jump = max(jump, i + nums[i]);
            if(i == last)
            {
                last = jump;
                count++;
            }
        }
        return count;
    }
};
