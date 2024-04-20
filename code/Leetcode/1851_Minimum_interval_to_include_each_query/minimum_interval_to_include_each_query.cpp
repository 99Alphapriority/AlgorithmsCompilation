class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        int n = intervals.size();
        int m = queries.size();
        vector<int> ans(m, -1);
        vector<pair<int, int>> queryPair;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < queries.size(); i++) {
            queryPair.push_back({queries[i], i});
        }
        sort(queryPair.begin(), queryPair.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int i =0;

        for(int j = 0; j < m; j++)
        {
            int query = queryPair[j].first;

            while(i < n && intervals[i][0] <= query)
            {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            while(!pq.empty() && query > pq.top().second)
                pq.pop();
            
            if(!pq.empty())
                ans[queryPair[j].second] = pq.top().first;
            
        }

        return ans;
        
    }
};
