class Solution {
public:
    vector<vector<string>> keypad = 
    {
        {""},
        {""},
        {"a","b","c"},
        {"d","e","f"},
        {"g","h","i"},
        {"j","k","l"},
        {"m","n","o"},
        {"p","q","r","s"},
        {"t","u","v"},
        {"w","x","y","z"}
    };

    void dfs(string& digits, string curr, int i, vector<string>& ans)
    {
        if(i >= digits.length())
        {
            ans.push_back(curr);
            return;
        }

        for(int j = 0; j < keypad[digits[i] - '0'].size(); j++)
        {
            curr += keypad[digits[i] - '0'][j];
            dfs(digits, curr, i + 1, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        string curr;

        if(digits.length() == 0)
            return ans;

        dfs(digits, curr, 0, ans);

        return ans;

    }
};
