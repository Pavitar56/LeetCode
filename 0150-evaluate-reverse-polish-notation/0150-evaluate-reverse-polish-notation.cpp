class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        
        stack<long long int> stk;
        
        for(int i=0;i<tokens.size();i++)
        {
            string curr = tokens[i];
            if(curr == "+" || curr == "*" || curr == "/" || curr == "-")
            {
                long long int b = stk.top();
                stk.pop();
                long long int a = stk.top();
                stk.pop();
                
                if(curr == "+")
                {
                    stk.push(a+b);
                }
                else if(curr == "-")
                {
                    stk.push(a-b);
                }
                else if(curr == "/")
                {
                    stk.push(a/b);
                }
                else
                {
                    stk.push(a*b);
                }
                
            }
            else
            {
                stk.push(stoll(curr));
            }
            
            
        }
        
        
        return stk.top();
        
        
    }
};