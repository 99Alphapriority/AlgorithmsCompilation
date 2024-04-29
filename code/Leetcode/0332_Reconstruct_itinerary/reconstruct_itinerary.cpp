class Solution {
public:
    vector<string> ans;
    unordered_map<string, multiset<string>> mp;

    void dfs(string src)
    {
        while(!mp[src].empty())
        {
            string next = *mp[src].begin();
            mp[src].erase(mp[src].begin());
            dfs(next);
        }
        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto &vec: tickets)
        {
            mp[vec[0]].insert(vec[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
