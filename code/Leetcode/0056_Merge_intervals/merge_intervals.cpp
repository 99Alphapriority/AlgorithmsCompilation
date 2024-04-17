class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        if(n == 1)
            return intervals;
        
        for(int i = 0; i < n - 1; i++)
        {
            if(intervals[i][1] >= intervals[i + 1][0])
            {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        ans.push_back(intervals[n-1]);
        return ans;
        
    }
};
