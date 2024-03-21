class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int start = 0;
        int end = 0;

        int count[26];
        int ans = 0;
        int maxCount = 0;

        while(end < s.size())
        {
            count[s[end] - 'A']++;

            maxCount = max(maxCount, count[s[end] - 'A']);

            if(end - start + 1 - maxCount > k )
            {
                count[s[start] - 'A']--;
                start++;
            }

            ans = max(ans, end - start + 1);
            end++;

        }

        return ans;
    }
};
