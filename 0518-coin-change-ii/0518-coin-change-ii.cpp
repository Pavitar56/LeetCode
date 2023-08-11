class Solution {
public:
    
    
    int solve(vector<int> &coins,int amount,int ind,vector<vector<int>> &dp)
    {
        if(amount == 0)
        {
            return 1;
        }
        
        if(amount < 0)
        {
            return 0;
        }
        if(ind >= coins.size())
        {
            return 0;
        }
        
        if(dp[ind][amount] != -1)
        {
            return dp[ind][amount];
        }
        
        int not_Take = solve(coins,amount,ind+1,dp);
        
        
        int take = solve(coins,amount-coins[ind],ind,dp);
     
        
        return dp[ind][amount] = take + not_Take;
        
        
    }
    
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return  solve(coins,amount,0,dp);
    }
};