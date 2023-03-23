class Solution {
public:
    
    
    void dfs(int curr,vector<vector<int>> &adj,vector<int> &visited)
    {
        visited[curr] = 1;
        
        for(int i=0;i<adj[curr].size();i++)
        {
            if(visited[adj[curr][i]] == 0)
            {
                dfs(adj[curr][i],adj,visited);
            }
        }
        
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < (n-1))
        {
            return -1;
        }
        
        vector<int> visited(n,0);
        
        vector<vector<int>> adj(n,vector<int>());
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        //cout<<count<<" "<<connections.size()<<endl;
       
        
        return count-1;
    }
};