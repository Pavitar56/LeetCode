class Solution {
public:
    int helper(vector<vector<int>>& matrix,int curRow,int curCol,int rows,int cols,vector<vector<int>> &dp)
     {
//         if(curRow == (rows-1))
//         {
//             return matrix[curRow][curCol];
//         }
        
//         if(dp[curRow][curCol] != -1)
//         {
//             return dp[curRow][curCol];
//         }
        
        
//         int sum = INT_MAX;
        
//         sum = min(sum,helper(matrix,curRow+1,curCol,rows,cols,dp));
        
//         if((curCol - 1) >= 0)
//         {
//             sum = min(sum,helper(matrix,curRow+1,curCol-1,rows,cols,dp));
//         }
        
//         if((curCol + 1) < rows)
//         {
//             sum = min(sum,helper(matrix,curRow+1,curCol+1,rows,cols,dp));
//         }
        
        
//         return dp[curRow][curCol] = sum + matrix[curRow][curCol];
        
        for(int i=0;i<cols;i++)
        {
            dp[rows-1][i] = matrix[rows-1][i];
        }
        
        
        for(int curRow = rows-2;curRow>=0;curRow--)
        {
            for(int curCol = 0;curCol<cols;curCol++)
            {
                int sum = INT_MAX;

                sum = min(sum,dp[curRow+1][curCol]);

                if((curCol - 1) >= 0)
                {
                    sum = min(sum,dp[curRow+1][curCol-1]);
                }

                if((curCol + 1) < rows)
                {
                    sum = min(sum,dp[curRow+1][curCol+1]);
                }


                dp[curRow][curCol] = sum + matrix[curRow][curCol];
            }
            
            
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<cols;i++)
        {
            ans = min(ans,dp[0][i]);
        }
        
        return ans;
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        
        
        int ans = INT_MAX;
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        
        
            
        ans = helper(matrix,0,0,rows,cols,dp);
            
        
        
        return ans;
        
//         int n=matrix.size();
        
//         int m=matrix[0].size();
        
//         vector<vector<int>>dp(n,vector<int>(m,0));
        
        
//         for(int j=0;j<m;j++)
//         {
//             dp[0][j]=matrix[0][j];
            
//         }
        
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 int ld=1e9,rd=1e9;
                
                
//                 int up=matrix[i][j] + dp[i-1][j];
                
//                 if(j-1>=0)
//                     ld=matrix[i][j] + dp[i-1][j-1];
//                 if(j+1<m)
//                     rd=matrix[i][j] + dp[i-1][j+1];
                
//                 dp[i][j] = min(up,min(ld,rd));
                
                
                
//             }
//         }
        
//         int mini=dp[n-1][0];
        
//         for(int j=1;j<m;j++)
//         {
            
//             mini=min(mini,dp[n-1][j]);
            
//         }
//         return mini;
        
        
        
    }
    
    
};