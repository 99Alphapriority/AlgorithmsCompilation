class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int i, int parent)
    {
        int edges = 0;

        for(auto child: adj[i])
        {
            if(child == parent)
               continue; 
            edges += dfs(adj, hasApple, child, i);
        }

        if(i == 0)
            return edges;

        if(edges > 0 || hasApple[i])
        {
            return edges + 1;
        }
        return edges;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj (n);

        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return 2 * dfs(adj, hasApple, 0, -1);
    }
};
