class Solution {
public:
    
    
    bool dfs(vector<vector<int>>& graph,int node,int parent,int c,vector<int> &visited,vector<int> &color)
    {
        visited[node] = 1;
        color[node] = c;
        
        for(int i=0;i<graph[node].size();i++)
        {
            int nNode = graph[node][i];
            
            if(!visited[nNode])
            {
                if(dfs(graph,nNode,node,!c,visited,color) == false)
                {
                    return false;
                }
            }
            else if(nNode != parent && color[nNode] == color[node])
            {
                return false;
            }
            
        }
        
        return true;
        
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int> visited(graph.size(),0);
        vector<int> color(graph.size(),-1);
        
        
        int vertexes = graph.size();
        
        for(int i=0;i<vertexes;i++)
        {
            if(!visited[i])
            {
                if(dfs(graph,i,-1,0,visited,color) == false)
                {
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
};