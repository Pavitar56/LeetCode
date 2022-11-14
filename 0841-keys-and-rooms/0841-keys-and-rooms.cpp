class Solution {
public:
    
    void dfs(int node,vector<vector<int>> &adj,vector<int> &visited)
    {
        visited[node] = 1;
       
        
        for(int i=0; i < adj[node].size() ;i++)
        {
            int nNode = adj[node][i];
            
            if(!visited[nNode])
            {
                dfs(nNode,adj,visited);
                
            }
           
              
        }
  
        return;
        
    }
    
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        
        //rooms is adj list
        
        
        int totalVertexes = rooms.size();
        
        vector<int> visited(totalVertexes,0);
        
        dfs(0,rooms,visited); 
        
        
        
        
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i] == 0) //means all rooms were not visited
            {
                return false;
            }
        }
        
        return true;
    }
};