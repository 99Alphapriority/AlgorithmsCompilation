class TrieNode{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        for(int i = 0; i< 26; i++)
            children[i] = NULL;

        isEndOfWord = false;
    }
};

class Solution {
public:
    
    TrieNode *root = new TrieNode();
    void insert(string word)
    {
        TrieNode *curr = root;

        for(char ch: word)
        {
            int idx = ch - 'a';

            if(curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    int dfs(string s, vector<int>& dp, int idx)
    {
        if(idx == s.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int res = 1 + dfs(s, dp, idx + 1); //skip current character
        TrieNode *curr = root;

        for(int i = idx; i < s.length(); i++)
        {
            if(curr->children[s[i] - 'a'] == NULL)
                break;
            curr = curr->children[s[i] - 'a'];

            if(curr->isEndOfWord)
                res = min(res, dfs(s, dp, i + 1));
        }

        return dp[idx] = res;        
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        for(auto &word: dictionary)
            insert(word);

        vector<int> dp(s.size(), -1);
        
        return dfs(s, dp, 0);
    }
};
