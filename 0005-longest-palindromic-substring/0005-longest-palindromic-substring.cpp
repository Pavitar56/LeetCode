class Solution {
public:
    bool checkpalindrome(string &s ,int start,int end)
    {
        while(start<end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
        
    }
    string longestPalindrome(string s) 
    {
        int maximum = INT_MIN;
        int start=0;
        int end =0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(checkpalindrome(s,i,j))
                {
                    if((j-i+1) > maximum)
                    {
                        maximum = j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        
        string ans="";
        
        for(int i=start;i<=end;i++)
        {
            ans +=s[i];
        }
        return ans;
        
        
    }
};