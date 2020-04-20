class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows==0)
            return 0;
        int col = grid[0].size();
        int dp[rows][col];
        dp[0][0] = grid[0][0];
        for(int i=1;i<col;i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int j=1;j<rows;j++)
        {
            dp[j][0]= dp[j-1][0] + grid[j][0];
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<col;j++)
            {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[rows-1][col-1];
    }
};