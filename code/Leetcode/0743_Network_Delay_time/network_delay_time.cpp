class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> mp;

        for(auto &vec: times)
        {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            mp[u].push_back({v,w});
        }


        vector<int> nodes(n + 1, INT_MAX);
        nodes[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k});

        while(!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto &vec: mp[node])
            {
                if(time + vec.second < nodes[vec.first])
                {
                    nodes[vec.first] = time + vec.second;
                    pq.push({nodes[vec.first], vec.first});
                }
            }
        }

        int ans = INT_MIN;

        for(int i = 1; i <= n; i++)
        {
            ans= max(ans, nodes[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
