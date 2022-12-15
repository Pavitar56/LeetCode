class Solution {
public:
    
    int helper(string &t1,string &t2,int idx1,int idx2,vector<vector<int>> &dp)
    {
        if(idx1 < 0 || idx2 < 0)
        {
            return 0;
        }
        
        if(dp[idx1][idx2] != -1)
        {
            return dp[idx1][idx2];
        }
        
        if(t1[idx1] == t2[idx2])
        {
            return dp[idx1][idx2] = 1 + helper(t1,t2,idx1-1,idx2-1,dp);
        }
        else
        {
            return dp[idx1][idx2] = max(helper(t1,t2,idx1,idx2-1,dp),helper(t1,t2,idx1-1,idx2,dp));
        }
        
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return helper(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};