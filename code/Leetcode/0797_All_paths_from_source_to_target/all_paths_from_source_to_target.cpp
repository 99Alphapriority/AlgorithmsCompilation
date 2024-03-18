class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& curr, int i, int n)
    {
        if(/*graph[i].empty() &&*/ i == n)
        {
            curr.push_back(i);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }

        curr.push_back(i);

        for(int j = 0; j < graph[i].size(); j++)
        {
            dfs(graph, ans, curr, graph[i][j], n);
            
        }

        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        int n = graph.size() - 1;
        vector<vector<int>> ans;
        vector<int> curr;

        dfs(graph, ans, curr, 0, n);

        return ans;
    }
};
