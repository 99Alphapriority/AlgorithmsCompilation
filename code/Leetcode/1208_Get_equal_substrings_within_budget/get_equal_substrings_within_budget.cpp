class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        vector<int> diff (s.size() + 1, 0);

        for(int i = 0; i < s.length(); i++)
        {
            diff[i+1] = diff[i] + abs(s[i] - t[i]);
        }

        int i = 0, j = 0, len = 0;

        for(j = 0; j < s.size(); j++)
        {
            int cost = diff[j+1] - diff[i];
            while(cost > maxCost)
            {
                cost = diff[j+1]-diff[++i];
            }
            len = max(len, j-i+1);
        }
        return len;
    }
};
