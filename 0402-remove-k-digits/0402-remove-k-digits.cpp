class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(num.size() <= k)
        {
            return "0";
        }
        
        if(k==0)
        {
            return num;
        }
        
        stack<char> stk;
        
        for(int i=0;i<num.size();i++)
        {
            while(k > 0 && !stk.empty() && num[i] < stk.top())
            {
                stk.pop();
                k--;
            }
            
            stk.push(num[i]);
            
            
        }
        
//         if(stk.empty())
//         {
//             return "0";
//         }
        
        while(k && !stk.empty())
        {
            stk.pop();
            k--;
        }
        
        string ans="";
        
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        int ei =0;
        
        while(ei < ans.size() && ans[ei] == '0')
        {
            ei++;
        }
        
        ans =  ans.substr(ei);
        
        if(ans.size()==0)
        {
            return "0";
        }
        
        return ans;
    }
};