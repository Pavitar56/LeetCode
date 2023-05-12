class Solution {
public:
    
    
    long long solve(vector<vector<int>>& questions,int idx,vector<long long int> &dp)
    {
        
        if(idx >= questions.size())
        {
            return 0;
        }
        
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        
        long long int notTake = solve(questions,idx+1,dp);
        long long int take = solve(questions,idx + questions[idx][1] + 1,dp) + questions[idx][0];
        
        return dp[idx] = max(take,notTake);
        
        
    }
    
    
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        vector<long long int> dp(questions.size(),-1);
        return solve(questions,0,dp);
        
        
        
        
        
        
    }
};