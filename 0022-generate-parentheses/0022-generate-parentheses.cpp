class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        if(n == 1)
        {
            return {"()"};
        }
        
        
        vector<string> prev = generateParenthesis(n-1);
        
        vector<string> ans;
        
        for(int i=0;i<prev.size();i++)
        {
            string curr = prev[i];
            
            ans.push_back("()" + curr);
            
           
            int j=0;
            
            while(j<curr.size())
            {   
                
                while(curr[j] != ')')
                {
                   
                    j++;
                }
                
                if(curr[j] == ')')
                {
                    string n = "(" + curr.substr(0,j+1) + ")" + curr.substr(j + 1);
                    
                    bool flag = true;
                    for(int k = 0;k<ans.size();k++)
                    {
                        if(n == ans[k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    
                    if(flag  == true)
                    {
                        ans.push_back(n);
                    }
                    
                    
                }
                
                j++;
            }
            
        }
        
        
        return ans;
        
    }
};