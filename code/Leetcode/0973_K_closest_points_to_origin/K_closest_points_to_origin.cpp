class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> data; // stores the distance from origin and the coordinates
        vector<vector<int>> ans;

        for(auto &p : points)
        {
            data.push_back({(p[0] * p[0]) + (p[1] * p[1]), p[0], p[1]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(data.begin(), data.end());

        while(k--)
        {
            vector<int> curr = pq.top();
            pq.pop();
            ans.push_back({curr[1], curr[2]});
        }
        return ans;
    }
};
