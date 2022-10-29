class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int open = 0;
        int close = 0;
        
        string temp = "";
        int i=0;
        
        for(int j=0;j<s.size();j++)
        {
            if(s[j] == '(')
            {
                open++;
                temp += s[j];
                //s[i] = s[j];
                //i++;
            }
            else if(s[j] == ')')
            {
                if(open>=1)
                {
                    open--;
                    temp += s[j];
                    //s[i] = s[j];
                  //  i++;
                }
                
            }
            else
            {
                temp += s[j];
               // s[i]=s[j];
                //i++;
            }
     
        }
        
        if(open == 0)
        {
            return temp;
        }
        
        string ans = "";
        open = 0;
        close = 0;
        
        for(int j = temp.size()-1;j>=0;j--)
        {
            if(temp[j] == ')')
            {
                close++;
                ans += temp[j];
            }
            else if(temp[j] == '(')
            {
                if(close >= 1)
                {
                    close--;
                    ans += temp[j];
                }
            }
            else
            {
                ans += temp[j];
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};