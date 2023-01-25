class Solution {
public:
    
    void solve(vector<vector<int>> &adj,vector<int> &dis,int n)
    {
        
        queue<pair<int,int>> q;
        q.push({n,0});
        dis[n] = 0;
        
        while(!q.empty())
        {
            int curr = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            for(int i=0;i<adj[curr].size();i++)
            {
                int newNode = adj[curr][i];
                int newDistance = distance + 1;
                
                if(dis[newNode] > newDistance)
                {
                    q.push({newNode,newDistance});
                    dis[newNode] = newDistance;
                }
                
            }
            
        }
        
        
    }
    
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>> adj(edges.size(),vector<int>());
        
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i] == -1)
            {
                continue;
            }
            
            adj[i].push_back(edges[i]);
            
        }
        
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(int j=0;j<adj[i].size();j++)
        //     {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> dis1(edges.size(),INT_MAX);
        vector<int> dis2(edges.size(),INT_MAX);
        
        solve(adj,dis1,node1);
        solve(adj,dis2,node2);
        
//         for(int i=0;i<dis1.size();i++)
//         {
//             cout<<dis1[i]<<" ";
//         }
//         cout<<endl;
        
        
//         for(int i=0;i<dis2.size();i++)
//         {
//             cout<<dis2[i]<<" ";
//         }
//         cout<<endl;
        
        int minDis = INT_MAX;
        int ans = -1;
        for(int i=0;i<dis1.size();i++)
        {
            if(dis1[i] == INT_MAX || dis2[i] == INT_MAX)
            {
                continue;
            }
            
            int temp = max(dis1[i],dis2[i]);
            
            
            if(temp < minDis)
            {
                minDis = temp;
                ans = i;
            }
            
        }
        
        return ans;
    }
};