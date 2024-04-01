class WordDictionary {
public:
    typedef struct trie
    {
        bool isEndOfWord;
        struct trie *children[26];
    }trie_st;

    trie_st* root;

    WordDictionary() {

        root = new trie_st(false);
        memset(root->children, NULL, sizeof(root->children));    
    }
    
    void addWord(string word) {
        trie_st *crawl = root;

        for(char ch: word)
        {
            int idx = ch - 'a';

            if(crawl->children[idx] == NULL)
                crawl->children[idx] = new trie_st(false);
            
            crawl = crawl->children[idx];
        }
        crawl->isEndOfWord = true;
    }

    bool searchInNode(string& word, int i, trie_st* crawl) {
        if (crawl == NULL) {
            return false;
        }
        if (i == word.size()) {
            return crawl->isEndOfWord;
        }
        if (word[i] != '.') {
            return searchInNode(word, i + 1, crawl->children[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, i + 1, crawl->children[j])) {
                return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        trie_st *crawl = root;

        return searchInNode(word, 0, crawl);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
