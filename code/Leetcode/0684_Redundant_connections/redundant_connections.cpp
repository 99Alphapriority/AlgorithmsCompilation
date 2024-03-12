class Solution {
public:

    int doFind(vector<int>& parents, int node)
    {
        int parent = parents[node];

        while(parent != parents[parent])
        {
            parents[parent] = parents[parents[parent]];
            parent = parents[parent];
        }

        return parent;
    }

    bool doUnion(vector<int>& parents, vector<int>& ranks, int node1, int node2)
    {
        int p1 = doFind(parents, node1);
        int p2 = doFind(parents, node2);

        if(p1 == p2)
            return false;

        if(ranks[p1] > ranks[p2])
        {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        }
        else
        {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int nodes = edges.size();

        vector<int> parents;
        vector<int> ranks;

        for(int i = 0; i <=nodes; i++)
        {
            parents.push_back(i);
            ranks.push_back(1);
        }

        vector<int> ans;

        for(int i = 0; i < nodes; i++)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];

            if(!doUnion(parents, ranks, node1, node2))
            {
                ans = {node1, node2};
                return ans;
            }
        }

        return ans;
    }
};
