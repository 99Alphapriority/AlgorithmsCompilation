class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(1 == n)
            return 0;

        sort(intervals.begin(), intervals.end());
        
        int i = 0;
        int result = 0;

        while (i < n - 1) {
            if (intervals[i][1] > intervals[i+1][0]) {
                if (intervals[i][1] < intervals[i+1][1]) {
                    intervals[i+1] = intervals[i];
                }
                result++;
            }
            i++;
        }

        return result;
    }
};
