class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;
        int fresh = 0;

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        if(q.empty() && fresh == 0)
            return 0;

        vector<vector<int>> dir = {{-1, 0}, {1,0}, {0, -1}, {0,1}};

        while(!q.empty())
        {   int size = q.size();

            for(int i = 0; i < size; i++)
            {
                int row = q.front().first;
                int col = q.front().second;

                q.pop();

                for(int i = 0; i < dir.size(); i++)
                {
                    int x = row + dir[i][0];
                    int y = col + dir[i][1];

                    if(x < 0 || x >= m || y < 0 || y >= n || (grid[x][y] != 1))
                        continue;

                    grid[x][y] = 2;
                    q.push({x,y});
                    fresh--;
                }

                
            }
            ans++;
        }

        if(fresh == 0)
            return ans;
        
        return -1;
        
    }
};
