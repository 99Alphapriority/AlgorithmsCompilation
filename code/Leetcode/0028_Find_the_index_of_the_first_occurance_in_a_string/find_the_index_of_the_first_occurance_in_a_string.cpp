class Solution {
public:
    int strStr(string haystack, string needle) {

        int s1 = haystack.length();
        int s2 = needle.length();

        int i = 0, j = 0, idx = -1, l = 0;

        while(i < s1)
        {
            if(haystack[l] == needle[j])
            {
                if(idx == -1)
                    idx = i;
                
                if(j == s2-1)
                    return idx;

                l++;
                j++;
            }
            else
            {
                i++;
                l = i;

                if(idx != -1)
                {
                    idx = -1;
                    j = 0;
                    
                }
            }
        }

        return -1;
        
    }
};
