class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        std::stack<int> s;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int max_width = 0;
        
        for (int j = n - 1; j >= 0; j--) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                max_width = std::max(max_width, j - s.top());
                s.pop();
            }
        }
        
        return max_width;
    }
};
