class Solution {
public:
    string countAndSay(int n) 
    {
        
        if(n==1)
        {
            return "1";
        }
        
        string temp = countAndSay(n-1);
        
        string ans="";
        
        int len=temp.size();
        int si=0;
        int ei=0;
        
        char t = temp[si];
        
        while(ei<len)
        {
            while(ei<len && temp[si] == temp[ei])
            {
                ei++;
            }
            
            
            int count = ei- si;
            
            ans += to_string(count) + temp[si];
            si=ei;
            
        }
        
        return ans;
        
        
    }
};