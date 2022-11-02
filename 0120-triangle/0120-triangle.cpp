class Solution {
public:
    
    int helper(vector<vector<int>>& triangle,int row,int col,vector<vector<int>> &dp)
    {
        int m = triangle.size();
        int n = triangle[row].size();
        
        if(row < 0 || row >=m || col < 0 || col >=n)
        {
            return INT_MAX;
        }
        
        if(row == m-1)
        {
            return triangle[row][col];
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int sum1 = helper(triangle,row+1,col,dp);
        int sum2 = helper(triangle,row+1,col+1,dp);
        
        int ans = min(sum1,sum2) + triangle[row][col];
        
        dp[row][col] = ans;
        
        return ans;
        
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        
        return helper(triangle,0,0,dp);
        
        
        
        
    }
};