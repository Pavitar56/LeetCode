class Solution {
public:
//     int helper(int n,vector<int>& dp)
//     {
//         if(n == 0)
//         {
//             return 0;
//         }
        
//         if(n<0)
//         {
//             return INT_MAX;
//         }
        
//         if(dp[n] != -1)
//         {
//             return dp[n];
//         }
        
//         int ans = INT_MAX;
        
//         for(int i=1;i<=sqrt(n);i++)
//         {
//             ans = min(ans,1 + helper(n - (i*i) , dp));
            
//         }
        
//         dp[n] = ans;
//         return ans;
        
//     }
    
    int numSquares(int n) {
        
//         vector<int> dp(n+1,-1);
//         helper(n,dp);
        
//         return dp[n];
        
        
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        
        for(int num = 1;num<=n;num++)
        {
            int ans = INT_MAX;
            for(int i=1;i<=sqrt(num);i++)
            {
                ans = min(ans,1 + dp[num - (i*i)]);

            }

            dp[num] = ans;
            
        }
        
        return dp[n];
    }
};