class Solution {
public:
    
    int helper(string &s,int start,int len,vector<int> &dp)
    {
        if(len == 0)
        {
            return 1;
        }
        
        if(s[start] == '0')
        {
            return 0;
        }
        
        if(len == 1)
        {
            return 1;
        }
        
//         if(len == 2)
//         {
//             int num = (s[start] - '0')*10 + s[start+1] - '0';
            
//             if(num == 10 || num ==20)
//             {
//                 return 1;
//             }
            
//             if(num%10 == 0)
//             {
//                 return 0;
//             }
            
//             if(num >= 1 && num<=26)
//             {
//                 return 2;
//             }
            
//             return 1;
            
//         }
        
        if(dp[len] != -1)
        {
            return dp[len];
        }
        
        int ans = 0;
        
        ans += helper(s,start+1,len-1,dp);
        
        int num = (s[start] - '0')*10 + s[start+1] - '0';
        if(num <=26)
        {
            ans += helper(s,start+2,len-2,dp);
        }
        dp[len] = ans;
        return ans;
        
    }
    int numDecodings(string s) 
    {
        
        vector<int> dp(s.size()+1,-1);
        
        return helper(s,0,s.size(),dp);
        
    }
};