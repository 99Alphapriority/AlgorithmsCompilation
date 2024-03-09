class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int size = nums.size();
        vector<int> ans;

        for(int i = 0; i<size; i++)
        {
            mp[nums[i]]++;
        }

        vector<vector<int>> container(size+1);

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            container[it->second].push_back(it->first);
        }

        for(int i = size; i>=0; i--)
        {
            if(ans.size() == k)
            {
                break;
            }
            if(!container[i].empty())
            {
                ans.insert(ans.end(), container[i].begin(), container[i].end());
            }
        }

        return ans;
        
    }
};
