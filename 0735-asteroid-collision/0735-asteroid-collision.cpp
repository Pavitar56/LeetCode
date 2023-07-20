class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> s;
        
        for(int i=0;i<asteroids.size();i++)
        {
            
            if(asteroids[i]>0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                if(s.empty() || s.top()<0)
                {
                    s.push(asteroids[i]);
                    continue;
                }
               
                while(!s.empty() && s.top()>0 && s.top() < abs(asteroids[i]))
                {
                    s.pop();
                }
                
                
                if(s.empty())
                {
                    s.push(asteroids[i]);
                    
                }
                else if(s.top()<0)
                {
                    s.push(asteroids[i]);
                }
                else if(s.top()==abs(asteroids[i]))
                {
                    s.pop();
                }
                
                  
            }
     
        }
        vector<int> ans(s.size());
        int i=s.size()-1;
        
        while(!s.empty())
        {
            ans[i]=s.top();
            s.pop();
            i--;
        }
        return ans;
        
    }
};