
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
    
    
    
    int min(int a,int b)
    {
        return (a>b)?b:a;
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        // vector<long long int> dp(questions.size(),-1);
        // return solve(questions,0,dp);
        
        vector<long long int> dp(questions.size() + 1,0);
        
        
        
        
        for(int idx = questions.size() - 1 ;idx >= 0;idx--)
        {
            
            long long int notTake = dp[idx+1];
            
            int nextPossible = min(questions.size() , idx + questions[idx][1] + 1);
            long long int take = dp[nextPossible] + questions[idx][0];
        
            dp[idx] = max(take,notTake);
        
            
        }
        
        return dp[0];
        
        
    }
};