class Solution {
public:

    string decodeString(string s) 
    {
        stack<char> stk;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ']') 
            {
                stk.push(s[i]);
                continue;
            }
           
            string curr_str = "";
                
            while(stk.top() != '[')
            {
                curr_str += stk.top();
                stk.pop();
            }
             
            reverse(curr_str.begin(),curr_str.end());
            
            stk.pop();   // for '['
            string number = "";
                
                // for calculating number
                
            while(!stk.empty() && isdigit(stk.top()))
            {
                number += stk.top();
                stk.pop();
            }
                
            reverse(number.begin(),number.end());
            
            int k_time = stoi(number);    // convert string to number
                
                
            while(k_time--)
            {
                for(int p = 0; p < curr_str.size() ; p++)
                    stk.push(curr_str[p]);
            }
            
        }
        
        s = "";
        
        while(!stk.empty())
        {
            s += stk.top();
            stk.pop();
        }
        
        reverse(s.begin(),s.end());
        
        return s;
        
    }
};