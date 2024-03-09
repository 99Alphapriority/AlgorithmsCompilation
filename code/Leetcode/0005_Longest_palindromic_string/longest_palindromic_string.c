bool t[1000][1000];

char* longestPalindrome(char* s) {
    int i = 0, j = 0, diff = 0;
    int n = strlen(s);
    int max = 0, start = 0;

    if(n == 1)
        return s;

    memset(t, false, sizeof(t));

    for(diff = 0; diff < n; diff++)
    {
        for(i = 0, j = diff; j < n; i++, j++)
        {
            if(i == j)
            {
                t[i][j] = true;
                if(j-i > max)
                    {
                        max = 0;
                        start = i;
                    }

            }
            else if(j == i + 1)
            {
                if(s[i] == s[j])
                {    t[i][j] = true;
                    if(j-i + 1> max)
                    {
                        max = j - i;
                        start = i;
                    }
                }
            }
            else
            {
                if(s[i] == s[j])
                {
                    if(true == t[i+1][j-1])
                    {    t[i][j] = true;
                        if(j-i > max)
                        {
                            max = j - i;
                            start = i;
                        }
                    }
                    else
                        t[i][j] = false;
                }
            }
        }
    }


    char *ans = (char*)malloc(sizeof(char) * (max + 2));

    for(i = 0; i<= max; i++)
    {
        ans[i] = s[start++];
    }    

    ans[i] = '\0';

    return ans;

}
