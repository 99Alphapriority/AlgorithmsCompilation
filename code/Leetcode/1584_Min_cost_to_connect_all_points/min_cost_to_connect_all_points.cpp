class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        //adjacency list
        vector<vector<pair<int, int>>> adj_list(points.size());
        int n = points.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;

                adj_list[i].push_back({(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), j});
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n, 0);
        pq.push({0,0});
        int ans = 0;

        while(!pq.empty())
        {
            int node = pq.top().second;
            int cost = pq.top().first;

            pq.pop();

            if(visited[node]) 
                continue;
            visited[node] = true;

            ans += cost;

            for(int i = 0; i < adj_list[node].size(); i++)
            {
                if(visited[adj_list[node][i].second])
                    continue;
                pq.push(adj_list[node][i]);
            }
        }

        return ans;

    }
};
