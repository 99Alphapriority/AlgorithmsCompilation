class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        int i = 0;
        int ans = 0;

        st.push(-1);

        while(s[i] != '\0')
        {
            if((st.top() != -1) && (s[i] == ')') && (s[st.top()] == '('))
            {
                st.pop();
                ans = max(ans, i - st.top());
            }
            else
                st.push(i);

            i++;
        }

        return ans;
    }
};
