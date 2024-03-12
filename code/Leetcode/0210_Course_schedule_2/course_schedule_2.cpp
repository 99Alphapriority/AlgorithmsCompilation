class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& mp, int course, unordered_set<int>& visited, vector<int>& ans, unordered_set<int>& completed)
    {
        if(visited.find(course) != visited.end())
            return false;

        if(completed.find(course) != completed.end())
            return true;

        visited.insert(course);
        for(int i = 0; i < mp[course].size(); i++)
        {
            int next = mp[course][i];
            if(!dfs(mp, next, visited, ans, completed))
            {
                return false;
            }
        }

        completed.insert(course);
        ans.push_back(course);
        visited.erase(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < prerequisites.size(); i++)
        {
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set<int> visited;
        unordered_set<int> completed;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(mp, i, visited, ans, completed))
            {
                return {};
            }
        }

        return ans;
        
    }
};
