class Solution {
public:

    vector<vector<int>> dir = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1)
            return 0;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        int ans = max(grid[0][0], grid[n - 1][n - 1]);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ans, 0, 0});

        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();

            ans = max(ans, curr[0]);

            for(int i = 0; i < 4; i++)
            {
                int x = curr[1] + dir[i][0];
                int y = curr[2] + dir[i][1];

                if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y] == true)
                    continue;

                if(x == n-1 && y == n-1)
                    return ans;

                pq.push({grid[x][y], x, y});
                visited[x][y] = true;
            }
        }

        return -1;       
    }
};
