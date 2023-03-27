class Solution {
public:
    
    int solve(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(r < 0 || r > grid.size()-1 || c < 0 || c > grid[0].size()-1)
        {
            return INT_MAX;
        }
        
        
        if(r == grid.size()-1 && c == grid[0].size()-1)
        {
            return grid[r][c];
        }
        
        if(dp[r][c] != -1)
        {
            return dp[r][c];
        }
        
        int c1 = solve(r,c+1,grid,dp);
        int c2 = solve(r+1,c,grid,dp);
        
        if(c1 == INT_MAX && c2 == INT_MAX)
        {
            return INT_MAX;
        }
        
        return dp[r][c] = min(c1,c2) + grid[r][c];
        
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        
        return solve(0,0,grid,dp);
    }
};