class Solution {
public:
    
//     int helper(vector<vector<int>>& obstacleGrid,int currRow,int currCol,int totalRows,                                         int totalCols,vector<vector<int>> &dp)
//     {
//         if(currRow < 0 || currRow >=totalRows || currCol < 0 || currCol >= totalCols)
//         {
//             return 0;
//         }
        
//         if(obstacleGrid[currRow][currCol] == 1)
//         {
//             return 0;
//         }
        
//         if(obstacleGrid[currRow][currCol] == 0 && currRow == (totalRows - 1) && currCol == (totalCols-1)) 
//         {
//             return 1;
//         }
        
//         if(dp[currRow][currCol] != -1)
//         {
//             return dp[currRow][currCol];
//         }
        
//         int right = helper(obstacleGrid,currRow, currCol+1,totalRows,totalCols,dp);
//         int down = helper(obstacleGrid,currRow + 1, currCol,totalRows,totalCols,dp);
        
//         dp[currRow][currCol] = down + right;
//         return down + right;
        
        
//     }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();
        
//         vector<vector<int>> dp(m,vector<int>(n,-1));
        
//         return helper(obstacleGrid,0,0,m,n,dp);
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m,(vector<int>(n,0))); 
        
        if(obstacleGrid[0][0] == 0)       //0 os space ,1 is obstacle
        {
            dp[0][0] = 1;
        }
        
        for(int k=1;k<m;k++)
        {
            if(obstacleGrid[k][0] != 1)
            {
                dp[k][0] = dp[k-1][0];
            }
        }
        
        for(int k=1;k<n;k++)
        {
            if(obstacleGrid[0][k] != 1)
            {
                dp[0][k] = dp[0][k-1];
            }
        }
        
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
        
        
        
        
        
        
    }
};