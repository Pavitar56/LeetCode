// class Solution {
// public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
//     {
        
//         vector<vector<int>> adj(n,vector<int>());
        
//         for(int i=0;i<edges.size();i++)
//         {
            
//             int u = edges[i][0];
//             int v = edges[i][1];
            
//             adj[u].push_back(v);
//             adj[v].push_back(u);
            
//         }
        
//         vector<int> ans(n,0);
        
//         for(int i=0;i<n;i++)
//         {
//             vector<int> visited(n,0);
            
//             //{node,distance}
//             queue<pair<int,int>> q;
//             q.push({i,0});
//             visited[i] = 1;
            
//             while(!q.empty())
//             {
//                 int node = q.front().first;
//                 int distance = q.front().second;
//                 q.pop();
                
//                 ans[i] += distance;
                
//                 for(int j=0;j < adj[node].size();j++)
//                 {
//                     int newNode = adj[node][j];
//                     int newDistance = distance + 1;
                    
//                     if(!visited[newNode])
//                     {
//                         q.push({newNode,newDistance});
//                         visited[newNode] = 1;
//                     }
                    
//                 }
                
                
//             }
            
//         }
        
//         return ans;
        
//     }
// };

class Solution {
public:
    vector<vector<int>> v;
    vector<int> counter, res;
        
    void dfs(int i, int p = -1) 
    {
        for(auto u : v[i]) 
        {
            if(u == p) 
                continue;
           
            dfs(u, i);
            counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs2(int i, int n, int p = -1) 
    {
        for(auto u : v[i]) 
        {
            if(u == p) 
                continue;
            res[u] = res[i] - counter[u] + n - counter[u];
            dfs2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v.resize(n);
        for(int i = 0; i < n - 1; i++) 
        {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        res.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);
        return res;
    }
};