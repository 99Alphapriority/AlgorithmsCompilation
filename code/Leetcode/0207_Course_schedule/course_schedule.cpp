class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& mp, int course, unordered_set<int>& visited)
    {
        if(visited.find(course) != visited.end())
            return false;

        if(mp[course].empty())
            return true;

        visited.insert(course);
        for(int i = 0; i < mp[course].size(); i++)
        {
            int next = mp[course][i];
            
            if(!dfs(mp, next, visited))
                return false;
        }

        mp[course].clear();
        visited.erase(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        int size = prerequisites.size();

        for(int i = 0; i < size; i++)
        {
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set<int> visited;

        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(mp, i, visited))
                return false;
        }

        return true;
    }
};
