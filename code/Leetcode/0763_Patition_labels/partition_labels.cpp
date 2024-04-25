class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n = s.size();
        vector<int> ans;

        if(s[0] == s[n-1])
        {
            ans.push_back(n);
            return ans;
        }

        unordered_map<char, int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        
        int i = 0, j = 0;
        unordered_set<char> st;

        while(j != n)
        {
            
            st.insert(s[j]);
            mp[s[j]]--;
            
            if(mp[s[j]] < 1)
                st.erase(s[j]);
            
            if(st.empty())
            {    
                ans.push_back(j - i + 1);
                i = j + 1;
            }
            
            j++;
        }

        return ans;
    }
};
