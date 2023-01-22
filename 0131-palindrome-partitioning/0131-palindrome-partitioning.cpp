class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPalindrome(string &s)
    {
        int i = 0;
        int j = s.size()-1;
        
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(string &s,int ind,vector<string> &curr)
    {
        
        if(ind == s.size())
        {
            if(curr.size() != 0)
            {
                ans.push_back(curr);
            }
            return;
        }
        
        
        for(int len = 1;len <= (s.size() - ind);len++)
        {
            string temp = s.substr(ind,len);
            
            if(isPalindrome(temp))
            {
                curr.push_back(temp);
                solve(s,ind + len,curr);
                curr.pop_back();
            }
            
            
        }
     
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s,0,curr);
        return ans;
    }
};