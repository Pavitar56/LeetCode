class Solution {
public:
    
    int solve(string &word1,string &word2,int i,int j,vector<vector<int>> &dp)
    {
        
        if(i == 0 || j == 0)
        {
            if(i==0 && j==0)
            {
                return 0;                
            }
            
            return max(i,j);
            
        }
        
        if(dp[i][j] != INT_MAX)
        {
            return dp[i][j];
            
        }
        
        
        if(word1[i-1] == word2[j-1])
        {
            return dp[i][j]=solve(word1,word2,i-1,j-1,dp);
        }
        else
        {
            int del = solve(word1,word2,i-1,j,dp);
            int insert = solve(word1,word2,i,j-1,dp);
            int replace = solve(word1,word2,i-1,j-1,dp);
            
            return dp[i][j] = 1 + min(del,min(insert,replace));
            
            
        }
        
        
    }
    
    
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,INT_MAX));
        return solve(word1,word2,word1.size(),word2.size(),dp);
    }
};