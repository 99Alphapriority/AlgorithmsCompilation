class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.length() != 1)
        {
            int n = s.length();

            if(s[n-1] == '0')
                s.pop_back();
            else
            {
                int num = 1;
                for(int i = n-1; i >= 0; i--)
                {
                    if(s[i] == '1' && num == 1)
                        s[i] = '0';
                    else if(s[i] == '0' && num == 1)
                    {
                        s[i] = '1';
                        num = 0;
                        break;
                    }
                }
                if(num)
                    s = '1' + s;
            }
            ans++;
        }
        return ans;
    }
};
