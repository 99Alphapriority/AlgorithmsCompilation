class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        map<int, int> mp;
        int count = 0, max = 0;

        if(0 == nums.size())
            return 0;

        if(1 == nums.size())
            return 1;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }


        for(auto it = mp.begin(); it != mp.end();)
        {

            if(((it->first + 1) == ((++it)->first)) && (it->second >= 1))
            {
                count++;

                if(count>max)
                {
                    max = count;
                }
            }
            else
            {
                count = 0;
            }
        }
        return max + 1;
    }
};
