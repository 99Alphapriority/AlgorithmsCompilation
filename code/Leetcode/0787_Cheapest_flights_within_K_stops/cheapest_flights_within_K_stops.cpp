class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, vector<pair<int, int>>> mp;

        for(auto &vec: flights)
        {
            int from = vec[0];
            int to = vec[1];
            int price = vec[2];

            mp[from].push_back({to, price});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> nodes(n, INT_MAX);
        nodes[src] = 0;
        int steps = 0;
        
        while(!q.empty() && steps <=k)
        {
            int neighbours = q.size();
            steps++;

            while(neighbours--)
            {
                int node = q.front().first;
                int price = q.front().second;
                q.pop();

                for(auto &vec: mp[node])
                {
                    if(nodes[vec.first] > price + vec.second)
                    {    
                        nodes[vec.first] = price + vec.second;
                        q.push({vec.first,  nodes[vec.first]});
                    }
                }

            }
        }

        return nodes[dst] == INT_MAX ? -1 : nodes[dst];
    }
};
