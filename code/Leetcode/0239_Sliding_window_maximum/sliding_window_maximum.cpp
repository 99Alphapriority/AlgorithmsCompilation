class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> deck;
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            while(!deck.empty() && deck.front() <= i -k)
            {
                deck.pop_front();
            }

            while(!deck.empty() && nums[i] > nums[deck.back()])
            {
                deck.pop_back();
            }

            deck.push_back(i);

            if(i >= k -1)
            {
                ans.push_back(nums[deck.front()]);
            }
        }
        
        return ans;
    }
};
