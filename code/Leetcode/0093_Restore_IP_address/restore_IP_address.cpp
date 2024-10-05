class Solution {
public:
    void dfs(string current, int count, int prevDotIdx, vector<string> &ans)
    {
        if(count == 4 && prevDotIdx == current.size() - 1)
        {
            current.erase(current.begin() + current.size() - 1);
            ans.push_back(current);
            return;
        }

        for(int i = 1; i <=3; i++)
        {
            if(prevDotIdx + i >= current.size())
                return;
            
            string temp = current.substr(prevDotIdx + 1, i);
            int num = stoi(temp);

            if(num == 0 && temp.size() > 1)
                return;
            if(num != 0 && temp[0] == '0')
                return;
            if(num > 255)
                return;

            current.insert(prevDotIdx+i+1, ".");
            dfs(current, count + 1, prevDotIdx+i+1, ans);
            current.erase(current.begin() + prevDotIdx + i + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;
        dfs(s, 0, -1, ans);
        return ans;
    }
};
