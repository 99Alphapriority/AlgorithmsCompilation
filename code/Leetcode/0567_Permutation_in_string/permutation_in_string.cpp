class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int check[26];
        for(int i = 0; i < s1.length(); i++)
            check[s1[i] - 'a']++;

        for(int i = 0, j = 0; j< s2.length(); j++)
        {

            while(check[s2[j] - 'a'] == 0)
            {
                check[s2[i] - 'a']++;
                i++;
            }

            check[s2[j] - 'a']--;

            if(j - i + 1 == s1.length())
                return true;
        }
        return false;
    }
};
