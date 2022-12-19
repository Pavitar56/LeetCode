class Solution {
public:
    
    bool path(vector<vector<int>> &adj,int start,int end,vector<int> &visited)
    {
       
        
        if(start == end)
        {
            return true;
        }
        
        if(visited[start] == 1)
        {
            return false;
        }
         visited[start] = 1;
        for(int i=0;i<adj[start].size();i++)
        {
            int nNode = adj[start][i];
            
            if(visited[nNode] == 0 && path(adj,nNode,end,visited) == true)
            {
                return true;
            }
            
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> adj(n,vector<int>());
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        vector<int> visited(n,0);
        
        
        
        return path(adj,source,destination,visited);
        
        
    }
};