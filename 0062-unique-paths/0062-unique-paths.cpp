class Solution {
public:
    
    // int dfs(int m,int n,int i,int j,vector<vector<int>> &dp)
    // {
//         if(i<0 || i>m || j<0 || j>n)
//         {
//             return 0;
//         }
        
//         if(i == m-1 && j == n-1)
//         {
//             return 1;
//         }
        
        
//         if(dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
       
//         int down = dfs(m,n,i+1,j,dp); 
//         int right = dfs(m,n,i,j+1,dp);
        
        
//         dp[i][j] = down + right;
        
//         return down + right;
        
//     }
    
    int uniquePaths(int m, int n) 
    {
        
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
//         return dfs(m,n,0,0,dp);
        
        vector<vector<int>> dp(m, vector<int>(n, 1));//imp initialize with 1 all as at least 1 path exists
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];//sum of unique paths ending at adjacent top and left cells
            }
        }
        return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
        
    }
};