class Solution {
public:
    
//     int helper(string &t1,string &t2,int idx1,int idx2,vector<vector<int>> &dp)
//     {
//         if(idx1 == 0 || idx2 == 0)
//         {
//             return 0;
//         }
        
//         if(dp[idx1][idx2] != -1)
//         {
//             return dp[idx1][idx2];
//         }
        
//         if(t1[idx1-1] == t2[idx2-1])
//         {
//             return dp[idx1][idx2] = 1 + helper(t1,t2,idx1-1,idx2-1,dp);
//         }
//         else
//         {
//             return dp[idx1][idx2] = max(helper(t1,t2,idx1,idx2-1,dp),helper(t1,t2,idx1-1,idx2,dp));
//         }
        
        
//     }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        // vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        // return helper(text1,text2,text1.size(),text2.size(),dp);
        
        
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
//         for(int i=0;i<m;i++)
//         {
//             dp[i][0]=0;
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             dp[0][i]=0;
//         }
        
        for(int idx1 = 1;idx1<=m;idx1++)
        {
            for(int idx2 = 1;idx2 <=n ;idx2++)
            {
                if(text1[idx1-1] == text2[idx2-1])
                {
                    dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                }
                else
                {
                    dp[idx1][idx2] = max(dp[idx1][idx2-1],dp[idx1-1][idx2]);
                }
            }
        }
        
        return dp[m][n];
    }
};