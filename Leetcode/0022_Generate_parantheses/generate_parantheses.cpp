class Solution {
public:

    void solve(int open, int close, int n, string s, vector<string>& ans)
    {

        if((open == close) && (open == n))
        {
            ans.push_back(s);
            return;
        }
        
        if(open < n)
        {
            s += '(';
            solve(open+1, close, n, s, ans);
            s.pop_back();
        }

        if(close < open)
        {
            s+= ')';
            solve(open, close + 1, n, s, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string s = "";
        int open = 0;
        int close = 0;

        solve(open, close, n, s, ans);

        return ans;
    }
};
