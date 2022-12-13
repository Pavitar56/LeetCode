class Solution {
public:
    int helper(vector<vector<int>>& matrix,int curRow,int curCol,int rows,int cols,vector<vector<int>> &dp)
    {
        if(curRow == (rows-1))
        {
            return matrix[curRow][curCol];
        }
        
        if(dp[curRow][curCol] != -1)
        {
            return dp[curRow][curCol];
        }
        
        
        int sum = INT_MAX;
        
        sum = min(sum,helper(matrix,curRow+1,curCol,rows,cols,dp));
        
        if((curCol - 1) >= 0)
        {
            sum = min(sum,helper(matrix,curRow+1,curCol-1,rows,cols,dp));
        }
        
        if((curCol + 1) < rows)
        {
            sum = min(sum,helper(matrix,curRow+1,curCol+1,rows,cols,dp));
        }
        
        
        return dp[curRow][curCol] = sum + matrix[curRow][curCol];
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        
        int ans = INT_MAX;
        
        for(int i=0;i<cols;i++)
        {
            ans = min(ans,helper(matrix,0,i,rows,cols,dp));
            
        }
        
        return ans;
        
        
    }
};