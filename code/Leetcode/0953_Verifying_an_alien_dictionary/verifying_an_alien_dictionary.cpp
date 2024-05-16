class Solution {
public:
    bool dfs(string& first_word, string& second_word, unordered_map<char, int>& mp)
    {
        int i = 0; 
        int j = 0;

        while(i < first_word.size() && j < second_word.size())
        {
            int first = mp[first_word[i]];
            int second = mp[second_word[j]];

            if(first < second)
                return true;
            else if(second < first)
                return false;
            
            i++;
            j++;
        }
        return (first_word.size() <= second_word.size());
    }

    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 1)
            return true;

        unordered_map<char, int> mp;

        for(int i = 0; i < order.length(); i++)
            mp[order[i]] = i;

        for(int i = 1; i < words.size(); i++)
        {
            if(!dfs(words[i-1], words[i], mp))
                return false;
        }
        return true;
    }
};
