class Solution {
public:
    
    int ans = 0;
    
    int dfs(vector<vector<int>> &childs,int curr,string &s)
    {
        int maximum = 0;
        int sec_max = 0;
        for(int i=0;i<childs[curr].size();i++)
        {
            int children = dfs(childs,childs[curr][i],s);
            
            if(s[curr] == s[childs[curr][i]])
            {
                continue;
            }
            
            if(children > maximum)
            {
                sec_max = maximum;
                maximum = children;
            }
            else if(children > sec_max)
            {
                sec_max = children;
            }
            
            
        }
        
        ans = max(ans,maximum+sec_max+1);
        
        return maximum+1;
        
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        
        vector<vector<int>> childs(parent.size(),vector<int>());
        
        for(int i=1;i<parent.size();i++)
        {
            childs[parent[i]].push_back(i);
            
        }
        
        
        
        dfs(childs,0,s);
        
        return ans;
    }
};