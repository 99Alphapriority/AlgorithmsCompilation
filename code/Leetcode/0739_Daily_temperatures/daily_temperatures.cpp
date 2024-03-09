class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());

        if(1 == temperatures.size())
        {
            ans.push_back(0);
            return ans;
        }

        stack<int> st;
        st.push(0);

        for(int i = 1; i< temperatures.size(); i++)
        {
            while((!st.empty()) && (temperatures[i] > temperatures[st.top()]))
            {
                
                ans[st.top()] = i - st.top();
                //printf("popping %d\n",st.top());
                st.pop();
            }

            st.push(i);
            //printf("top %d\n",st.top());
        }

        return ans;
    }
};
