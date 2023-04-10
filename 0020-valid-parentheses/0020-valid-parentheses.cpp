class Solution {
public:
    bool isValid(string s) 
    {
        if(s.length()%2 != 0)
        {
            return false;
        }
        
        
        stack<char> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='{' || s[i]=='[' || s[i]=='(')
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.size()==0)
                {
                    return false;
                }
                char top=stk.top();
                if((top=='{' && s[i]=='}') || (top=='(' && s[i]==')') || (top=='[' && s[i]==']') )
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
                
            }
            
        }
        if(stk.size()!=0)
        {
            return false;
        }
        return true;
        
        
    }
};