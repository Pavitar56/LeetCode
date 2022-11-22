class Solution {
public:
    int helper(int n,vector<int>& dp)
    {
        if(n == 0)
        {
            return 0;
        }
        
        if(n<0)
        {
            return INT_MAX;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int ans = INT_MAX;
        
        for(int i=1;i<=sqrt(n);i++)
        {
            ans = min(ans,1 + helper(n - (i*i) , dp));
            
        }
        
        dp[n] = ans;
        return ans;
        
    }
    int numSquares(int n) {
        
        vector<int> dp(n+1,-1);
        helper(n,dp);
        
        return dp[n];
        
        
    }
};