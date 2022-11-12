class Solution {
    
    private:
    
    bool hasCycleDFS(int vertexes,int node,vector<vector<int>> &adj,vector<int> &visited,                                                 vector<int> &pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        
        for(int i=0; i < adj[node].size(); i++)
        {
            int neighNode = adj[node][i];
            
            if(!visited[neighNode])
            {
                bool check = hasCycleDFS(vertexes,neighNode,adj,visited,pathVisited);
                if(check == true)
                {
                    return true;
                }
                
            }
            else if(visited[neighNode] && pathVisited[neighNode])
            {
                return true;
            }
            
            
        }
        
        
        pathVisited[node] = 0;
        
        return false;
        
        
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);
        
        vector<vector<int>> adj(numCourses,vector<int>(0));
        
        
        for(int i=0 ; i<prerequisites.size() ;i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            
            adj[u].push_back(v);
            
            
        }
        
        
//         for(int i=0;i<numCourses;i++)
//         {
//             cout<<i<<"->";
            
            
//             for(int j=0;j<adj[i].size();j++)
//             {
//                 cout<<adj[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        
        for(int v= 0 ; v < numCourses;v++)
        {
            
            if(!visited[v])
            {
                bool check = hasCycleDFS(numCourses,v,adj,visited,pathVisited);
                if(check == true)
                {
                    return false;
                }
            }
            
        }
        
        return true;
        

    }
};