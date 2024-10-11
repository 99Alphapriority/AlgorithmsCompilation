class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int rowStart, int colStart)
    {
        vector<int> nums;   //store all the 9 digits of the 3x3 square

        for(int i = rowStart; i < rowStart + 3; i++)
        {
            for(int j = colStart; j < colStart + 3; j++)
            {
                nums.push_back(grid[i][j]);
            }
        }

        //to validate the stored digits are in range (1-9)
        sort(nums.begin(), nums.end()); 

        for(int i = 0; i < 9; i++)
        {
            if(nums[i] != i+1)
                return false;
        }

        int sum = grid[rowStart][colStart] + grid[rowStart][colStart + 1] + grid[rowStart][colStart + 2];

        for(int i = rowStart + 1; i < rowStart + 3; i++)
        {
            if(sum != grid[i][colStart] + grid[i][colStart + 1] + grid[i][colStart + 2])
                return false;
        }

        for(int j = colStart; j < colStart + 3; j++)
        {
            if(sum != grid[rowStart][j] + grid[rowStart + 1][j] + grid[rowStart + 2][j])
                return false;
        }

        if(sum != grid[rowStart][colStart] + grid[rowStart+1][colStart + 1] + grid[rowStart+2][colStart + 2])
            return false;
        
        if(sum != grid[rowStart][colStart + 2] + grid[rowStart+1][colStart + 1] + grid[rowStart+2][colStart])
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int count{0};

        for(int i = 0; i <= rows - 3; i++)
        {
            for(int j = 0; j <= cols -3; j++)
            {
                if(isValid(grid, i, j))
                    count++;
            }
        }
        return count;
    }
};
