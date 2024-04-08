class Solution {
public:
    int dp[301];

    bool solve(string& s, unordered_set<string>& mp, int idx, int n)
    {
        if(idx >= n)
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        if(mp.find(s) != mp.end())
            return dp[idx] = true;

        for(int l = 1; l <= n; l++)
        {
            string temp = s.substr(idx, l);
            
            if(mp.find(temp) != mp.end() && solve(s, mp, idx + l, n))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> mp;

        memset(dp, -1, sizeof(dp));

        for(string &word: wordDict)
            mp.insert(word);

        return solve(s, mp, 0, n);
    }
};
