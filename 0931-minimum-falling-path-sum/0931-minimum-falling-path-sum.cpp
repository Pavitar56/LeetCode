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
        
        return dp[0][curCol];
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        
        
        int ans = INT_MAX;
        
        for(int i=0;i<cols;i++)
        {
            vector<vector<int>> dp(rows,vector<int>(cols,0));
            ans = min(ans,helper(matrix,0,i,rows,cols,dp));
            
        }
        
        return ans;
        
        
        
        
        
    }
};