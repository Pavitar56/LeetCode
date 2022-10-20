class Solution {
public:
    
    int helper(vector<vector<int>>& obstacleGrid,int currRow,int currCol,int totalRows,                                         int totalCols,vector<vector<int>> &dp)
    {
        if(currRow < 0 || currRow >=totalRows || currCol < 0 || currCol >= totalCols)
        {
            return 0;
        }
        
        if(obstacleGrid[currRow][currCol] == 1)
        {
            return 0;
        }
        
        if(obstacleGrid[currRow][currCol] == 0 && currRow == (totalRows - 1) && currCol == (totalCols-1)) 
        {
            return 1;
        }
        
        if(dp[currRow][currCol] != -1)
        {
            return dp[currRow][currCol];
        }
        
        int right = helper(obstacleGrid,currRow, currCol+1,totalRows,totalCols,dp);
        int down = helper(obstacleGrid,currRow + 1, currCol,totalRows,totalCols,dp);
        
        dp[currRow][currCol] = down + right;
        return down + right;
        
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return helper(obstacleGrid,0,0,m,n,dp);
        
    }
};