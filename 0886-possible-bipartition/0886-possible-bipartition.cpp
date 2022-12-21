class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>> adj(n,vector<int>(0));
        
        
        for(int i=0;i<dislikes.size();i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
            
            
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> color(n,-1);
        vector<int> visited(n,0);
        
        for(int node=0;node<n;node++)
        {
            if(visited[node] == 1)
            {
                continue;
            }
            
            //{node,parent}
            queue<pair<int,int>> q;

            q.push({node,-1});
            color[node] = 0;
            visited[node] = 1;
            
            while(!q.empty())
            {
                
                int currNode = q.front().first;
                int parent = q.front().second;
                q.pop();
                
                for(int i=0;i<adj[currNode].size();i++)
                {
                    int newNode = adj[currNode][i];
                    
                    if(!visited[newNode])
                    {
                        color[newNode] = (!color[currNode]);
                        visited[newNode] = 1;
                        q.push({newNode,parent});
                    }
                    else if(parent != newNode && color[newNode] == color[currNode])
                    {
                        return false;
                    }
                   



                }
            }
               
        }
        
        return true;
    }
};