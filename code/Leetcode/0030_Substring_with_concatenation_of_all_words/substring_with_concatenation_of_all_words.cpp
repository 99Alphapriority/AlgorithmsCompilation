class Solution {
public:
    bool checkSubstring(string s, unordered_map<string, int> mp, int minWindowSize)
    {
        for(int i = 0; i< s.size(); i+= minWindowSize)
        {
            string msg = s.substr(i, minWindowSize);
            if(mp.find(msg) != mp.end())
            {
                if(--mp[msg] == -1)
                    return false;
            }
            else
                return false;
        } 
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        
        int minWindowSize = words[0].size();
        int wordsWindow = words.size() * minWindowSize;
        int size = s.size();
        unordered_map<string, int> mp;
        int i = 0;
       
        vector<int> ans;

        for(i=0; i<words.size(); i++) 
        {
            mp[words[i]]++;
        }

        i = 0;

        while(i + wordsWindow <= size) {
            if(checkSubstring(s.substr(i, wordsWindow) ,mp, minWindowSize)) {
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};
