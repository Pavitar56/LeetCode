class Solution {
public:
    
    void LeadRemove(string &s)
    {
        
        int i=0;
        while(s[i] == ' ')
        {
            i++;
        }
        
        
        s=s.substr(i);
    }
    
    
    void EndRemove(string &s)
    {
        int i=s.size()-1;
        
        while(s[i] == ' ')
        {
            i--;
        }
        
        s=s.substr(0,i+1);
    }
    
    void make(string &s,int start,int end,string &ans)
    {
        for(int i=end;i>=start;i--)
        {
            ans += s[i];
        }
        
        
        
    }
    
    string reverseWords(string s) 
    {
        
        
//         //removing extra spaces
        
        
//         //removing leading spaces
        
        
//         LeadRemove(s);
        
//         //removing ending spaces
        
//         EndRemove(s);
        
        
       // reverse(s.begin(),s.end());
        
        
        s.push_back(' ');
        
        
        int si = 0;
        int ei = 0;
        
        
        string ans="";
        
        while(ei < s.size())
        {
            while(s[ei] == ' ')
            {
                ei++;
            }
            si=ei;
            while(ei<s.size() && s[ei] != ' ')
            {
                ei++;
            }
            
            
            ans = s.substr(si,ei - si + 1) + ans;
         
        }
        
        ans.pop_back();
        return ans;
        
    }
};