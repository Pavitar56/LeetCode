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
    
    
    
    int helper(int row,int col,int m ,int n,vector<vector<int>> &dp)
    {
        if(row == m-1 && col == n-1)
        {
            return 1;
        }
        
        if(row >= m  || col >= n)
        {
            return 0;
        }
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int right = helper(row,col+1,m,n,dp);
        int down = helper(row+1,col,m,n,dp);
        
        
        return dp[row][col] = right + down;
        
        
        
    }
    int uniquePaths(int m, int n) 
    {
        
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
//         return dfs(m,n,0,0,dp);
        
        
        
        
// We start at cell (0, 0), so dp[0][0] = 1.
        
// Since we can only move right or down, there is only one way to reach a cell (i, 0) or (0, j). Thus, we also initialize dp[i][0] = 1 and dp[0][j]=1. 
        
// For every other cell (i, j) (where 1 <= i <= m-1 and 1 <= j <= n-1), we can reach here either from the top cell (i-1, j) or the left cell (i, j-1). So the result for number of unique paths to arrive at (i, j) is the summation of both, i.e, dp[i][j] = dp[i-1][j] + dp[i][j-1].
        
        //Dp solution TC :O(NM)
        
//         vector<vector<int>> dp(m, vector<int>(n, 1));//imp initialize with 1 all as at least 1 path exists
        
//         for(int i = 1; i < m; i++)
//         {
//             for(int j = 1; j < n; j++)
//             {
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];//sum of unique paths ending at adjacent top and left cells
//             }
//         }
//         return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
        
        
//         int prevLeft = 1;
//         //int prevTop =1;
//         int ans = 0;
//         vector<int> dp(n,1);
        
//         for(int i = 1;i<m;i++)
//         {
//             //int temp = ans;
//             for(int j=1;j<n;j++)
//             {
//                 ans = prevLeft + dp[j-1];
//                 prevLeft = ans;
//                 dp[j] = ans;
//             }
   
//         }
//         return dp[n-1];
        
   //     vector<vector<int>> dp(m,vector<int>(n,-1));
        
     //   return helper(0,0,m,n,dp);
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        dp[m-1][n-1] = 1;
        vector<int> front(n,0),curr(n,0);
        
        for(int row = m-1 ;row >=0 ;row--)
        {
            for(int col = n-1 ;col>=0;col--)
            {
                if(row == m-1 && col == n-1)
                {
                    curr[col] = 1;
                }
                else
                {
                    int right =0;
                    int down = 0;
                    if((col +1) < n)  right = curr[col+1];
                    if((row + 1) < m) down = front[col];
        
                    curr[col] = right + down;
                }
    
            }
            front= curr;
        }
        
        return front[0];
        
        
    }
};