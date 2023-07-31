class Solution {
public:
    
    int solve(string &s1,string &s2,int size1,int size2,vector<vector<int>> &dp)
    {
        if(size1 == 0 && size2 == 0)
        {
            return 0;
        }
        if(size1 == 0)
        {
            int sum = 0;
            for(int i=0;i<size2;i++)
            {
                sum += s2[i];
            }
            
            return sum;
        }
        
        if(size2 == 0)
        {
            int sum = 0;
            for(int i=0;i<size1;i++)
            {
                sum += s1[i];
            }
            return sum;
        }
        
        if(dp[size1][size2] != -1)
        {
            return dp[size1][size2];
        }
        
        if(s1[size1 - 1] == s2[size2 - 1])
        {
            return dp[size1][size2] = solve(s1,s2,size1-1,size2-1,dp);
        }
        else
        {
            int c1 = s1[size1-1]+solve(s1,s2,size1-1,size2,dp);
            int c2 = s2[size2-1]+solve(s1,s2,size1,size2-1,dp);
            
            return dp[size1][size2] = min(c1,c2);
        }
        
        
        
        
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
        
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        
        return solve(s1,s2,s1.size(),s2.size(),dp);
        
    }
};