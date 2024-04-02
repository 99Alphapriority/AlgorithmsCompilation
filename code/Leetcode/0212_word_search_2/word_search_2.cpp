class TrieNode {
public:
    TrieNode *children[26];
    bool isEndOfWord;
    
    TrieNode() {
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isEndOfWord = false;
    }
};

class Solution {
public:
    
    TrieNode* root = new TrieNode();
    void insert(string word)
    {
        TrieNode* crawl = root;

        for(char ch: word)
        {
            int idx = ch - 'a';

            if(crawl->children[idx] == NULL)
                crawl->children[idx] = new TrieNode();
            
            crawl = crawl->children[idx];
        }

        crawl->isEndOfWord = true;
    }


    void search(vector<vector<char>>& board, int i, int j, int m, int n, TrieNode* node, string word, vector<string>& ans)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#')
            return;
        
        char ch = board[i][j];

        node = node->children[ch - 'a'];
        if(node == NULL)
            return;

        word += board[i][j];

        if(node->isEndOfWord == true)
        {
            ans.push_back(word);
            node->isEndOfWord = false;
        }

        board[i][j] = '#';

        search(board, i + 1, j, m, n, node, word, ans);
        search(board, i - 1, j, m, n, node, word, ans);
        search(board, i, j + 1, m, n, node, word, ans);
        search(board, i, j - 1, m, n, node, word, ans);

        board[i][j] = ch;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for(int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }

        vector<string> ans;
        TrieNode* crawl = root;

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                search(board, i, j, m, n, crawl, "", ans);
            }
        }
        return ans;
    }

};
