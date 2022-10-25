class Solution {
public:
    
    int mod = 1000000007;
    vector<int> drow = {-2,-1,1,2,2,1,-1,-2};
    vector<int> dcol = {1,2,2,1,-1,-2,-2,-1};
    
    
    int helper(int row, int col, int n, vector<vector<vector<int>>> &dp)
    {
        if(row < 0 || row >= 4 || col < 0 || col >= 3 || (row == 3 && (col == 0 || col == 2)))
        {
           
            return 0;
        }
        
        if(n == 0)
        {
            return 1;
        }
        
        if(dp[row][col][n] != -1)
        {
            return dp[row][col][n];
        }
        
        
        long long int sum = 0;
        for(int k=0;k<8;k++)
        {
            sum = ((sum%mod) + helper(row + drow[k],col + dcol[k],n-1,dp) % mod)%mod;
            
        }
        
        dp[row][col][n] = sum;
        return sum;
        
        
    }
    
    
    int knightDialer(int n) 
    {
        
        
        vector<vector<vector<int>>> dp(4,(vector<vector<int>>(3,vector<int>(n+1,-1))));
        
        long long int finalans= 0 ;
        
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if((i == 3 && j == 0) || (i == 3 && j == 2))
                {
                    continue;
                }
               
                finalans = (finalans%mod + helper(i,j,n-1,dp)%mod)%mod;
                
            }
        }
        
        
        return finalans;
        
        
        
        
    }
};