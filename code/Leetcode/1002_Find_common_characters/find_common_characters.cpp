class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            int minCount = INT_MAX;

            for(string word: words)
            {
                int count = 0;
                for(char c: word)
                    if(c == ch)
                        count++;
                minCount = min(count, minCount);
            }

            for(int i = 0; i < minCount; i++)
                ans.push_back(string(1, ch));
        }        
        return ans;
    }
};
