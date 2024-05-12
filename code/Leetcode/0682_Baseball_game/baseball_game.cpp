class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;
        int ans = 0;

        for(int i = 0; i < operations.size(); i++)
        {
            if(operations[i] == "+")
            {
                int first = stk.top();
                stk.pop();
                int second = stk.top();

                stk.push(first);
                stk.push(first+second);

                ans += first + second;
            }
            else if(operations[i] == "C")
            {
                ans -= stk.top();
                stk.pop();
            }    
            else if(operations[i] == "D")
            {
                ans += 2 * stk.top();
                stk.push(2 * stk.top());
            }    
            else
            {
                int curr = stoi(operations[i]);
                ans += curr;
                stk.push( curr );
            }
                
        }
        return ans;
    }
};
