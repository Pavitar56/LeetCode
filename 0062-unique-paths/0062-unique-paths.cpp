class Solution {
public:
    
    int dfs(int m,int n,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || i>m || j<0 || j>n)
        {
            return 0;
        }
        
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
       
        int down = dfs(m,n,i+1,j,dp); 
        int right = dfs(m,n,i,j+1,dp);
        
        
        dp[i][j] = down + right;
        
        return down + right;
        
    }
    
    int uniquePaths(int m, int n) 
    {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        
        
        
        return dfs(m,n,0,0,dp);
        
    }
};