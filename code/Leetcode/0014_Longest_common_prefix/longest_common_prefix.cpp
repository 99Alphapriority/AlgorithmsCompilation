class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        
        int n = strs.size();

        if(n == 1)
            return strs[0];
        
        string first = strs[0], last = strs[n-1];
        int m = min(first.length(), last.length());

        for(int i = 0; i < m; i++)
        {
            if(first[i] != last[i])
                return ans;
            
            ans +=first[i];
        }
        return ans;
    }
};
