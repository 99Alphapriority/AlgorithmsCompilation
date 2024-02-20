class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int op1, op2, num;
        string s;
        int size = tokens.size();

        for(int i = 0; i<size; i++)
        {
            s = (tokens[i]);
            if((s != "+") && (s != "-") && (s != "*") && (s != "/"))
            {
                num = stoi(s);
                st.push(num);
            }
            else
            {
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();

                if(s == "+")
                    st.push((op1 + op2));
                else if(s == "-")
                    st.push((op1 - op2));
                else if(s == "*")
                    st.push((op1 * op2));
                else
                    st.push((op1 / op2));

            }
        }

        return st.top();
    }
};
