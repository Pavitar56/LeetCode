class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        
        vector<int> ans(temperatures.size(),0);
        
        ans[temperatures.size() - 1]=0;
        
        stack<vector<int>> stk;
        
        for(int i = temperatures.size() - 1;i>=0;i--)
        {
            while(!stk.empty() && temperatures[i] >= stk.top()[0])
            {
                stk.pop();
            }
            
            
            if(stk.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = stk.top()[1] - i;
            }
            
            stk.push({temperatures[i],i});
            
        }
        
        return ans;
    }
};