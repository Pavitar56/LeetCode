class Solution {
public:
    
    bool search(vector<string> &wordDict,string& w)
    {
        
        for(int i=0;i<wordDict.size();i++)
        {
            
            if(wordDict[i] == w)
            {
                
                return true;
            }
            
        }
        
        return false;
    }
    
    
    
    bool helper(string s,vector<string>& wordDict,unordered_map<string,bool> &dp)
    {
                
        if(s.size()==0)
        {
            return true;
        }
        
        if(search(wordDict,s) == true)
        {
            return true;
        }
        
        
        if(dp.count(s) > 0)
        {
            return dp[s];
        }
        
        
        for(int i=1;i<s.size();i++)       //imp note i starts from 1 bcz its size
        {
            string left = s.substr(0,i);
            
            if(search(wordDict,left) && helper(s.substr(i),wordDict,dp) )
            {
                dp[s] = true;
                return true;
            }
            
            
        }
        dp[s] = false;
        
        return false;
        
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        
//         if(s.size()==0)
//         {
//             return true;
//         }
        
//         if(search(wordDict,s) == true)
//         {
//             return true;
//         }
        
        
//         for(int i=1;i<s.size();i++)       //imp note i starts from 1 bcz its size
//         {
//             string left = s.substr(0,i);
            
//             if(search(wordDict,left) && wordBreak(s.substr(i),wordDict) )
//             {
//                 return true;
//             }
            
            
//         }
        
//         return false;
        
        unordered_map<string,bool> dp;
        
        return helper(s,wordDict,dp);
        
        
    }
};