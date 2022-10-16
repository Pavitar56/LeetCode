class Solution {
public:
    
    void dfs(vector<vector<int>> &isConnected,int sv,vector<bool> &visited)
    {
        visited[sv] = true;
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(sv==i)
            {
                continue;
            }
            if(visited[i])
            {
                continue;
            }
            
            if(isConnected[sv][i] == 1)
            {
                dfs(isConnected,i,visited);
            }
            
            
        }
        
        
        
    }
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        vector<bool> visited(isConnected.size(),false);
        int n=isConnected.size();
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i] == false)
            {
                dfs(isConnected,i,visited);
                count++;
            }
        }
        
        return count;
        
    }
};