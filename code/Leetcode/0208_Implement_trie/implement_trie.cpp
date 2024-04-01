class Trie {
public:
    typedef struct trie_st
    {
        bool isEndOfWord;
        struct trie_st *children[26];
    }trie_st;

    trie_st *root;

    Trie() {
        root = new trie_st(false);
        memset(root->children, NULL, sizeof(root->children));
    }
    
    void insert(string word) {
        trie_st* crawl = root;

        for(char ch: word)
        {
            int idx = ch - 'a';

            if(crawl->children[idx] == NULL)
            {
                crawl->children[idx] = new trie_st(false);
            }
            crawl = crawl->children[idx];
        }

        crawl->isEndOfWord = true;
        
    }
    
    bool search(string word) {
        trie_st *crawl = root;

        for(char ch: word)
        {
            int idx = ch - 'a';
            if(crawl->children[idx] == NULL)
                return false;
            crawl = crawl->children[idx];
        }
        
        return crawl->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        trie_st *crawl = root;

        for(char ch: prefix)
        {
            int idx = ch - 'a';
            if(crawl->children[idx] == NULL)
                return false;
            crawl = crawl->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
