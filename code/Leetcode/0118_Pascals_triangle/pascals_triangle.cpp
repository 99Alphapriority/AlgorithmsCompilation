class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        ans.push_back({1});

        for(int i = 1; i < numRows; i++)
        {
            vector<int> curr;

            for(int j = 0; j < i+1; j++)
            {
                if(j == 0)
                    curr.push_back(1);
                else if(j == i)
                    curr.push_back(1);
                else
                    curr.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
