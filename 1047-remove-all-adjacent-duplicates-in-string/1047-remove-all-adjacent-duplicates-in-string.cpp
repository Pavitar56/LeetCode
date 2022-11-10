class Solution {
public:
    string removeDuplicates(string s) 
    {
      
        stack<char> stk;
                
        for(int i=0;i<s.size();i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else if(s[i] == stk.top())
            {
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
            
        }
        
        
//         s[stk.size()] = '\0';
//         int i=stk.size() - 1;
        
        
//         while(!stk.empty())
//         {
//             s[i] = stk.top();
//             i--;
//             stk.pop();
//         }
//         return s;
        
        string ans="";
        
        while(!stk.empty())
        {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};