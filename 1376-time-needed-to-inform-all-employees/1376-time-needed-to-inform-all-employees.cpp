class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        
        vector<vector<int>> adj(n,vector<int>());
        
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i] == -1)
            {
                continue;
            }
            
            adj[manager[i]].push_back(i);
            
        }
        
        
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        // {node,informtime}
        vector<int> visited(n,0);
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        visited[headID] = 1;
        
        int maximum = INT_MIN;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            maximum = max(time,maximum);
            
            for(int i=0 ;i < adj[node].size(); i++)
            {
                int nNode = adj[node][i];
                int nTime = time + informTime[node];
                
                if(!visited[nNode])
                {
                    q.push({nNode,nTime});
                    visited[nNode] = 1;
                }
            }
            
        }
        
        return maximum;
        
    }
};