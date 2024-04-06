class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> mp;
        
        for(int i = 0; i < wordList.size(); i++)
            mp.insert(wordList[i]);

        queue<string> q;
        q.push(beginWord);
        int ans = 1;

        while(!q.empty())
        {
            int n = q.size();

            for(int i = 0; i < n; i++)
            {
                string word = q.front();
                q.pop();

                if(word == endWord)
                    return ans;
                
                mp.erase(word);

                for(int j = 0; j < word.size(); j++)
                {
                    char ch = word[j];
                    for(int k = 0; k < 26; k++)
                    {
                        word[j] = k + 'a';
                        if(mp.find(word) != mp.end())
                        {
                            q.push(word);
                            mp.erase(word);
                        }
                    }
                        word[j] = ch;
                }
            }
            ans++;
        }
        
        return 0;
    }
};
