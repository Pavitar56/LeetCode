class Solution {
public:
    
    void dfs(int curr,vector<vector<int>> &adj,vector<int> &visited,int &count)
    {
        visited[curr] = 1;
        count++;
        
        for(int i=0;i<adj[curr].size();i++)
        {
            if(visited[adj[curr][i]] == 0)
                dfs(adj[curr][i],adj,visited,count);
            
            
        }
        
        
        
    }
    
    
    
    
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        
        vector<int> visited(n,0);
        
        vector<vector<int>> adj(n,vector<int>());
        
        unordered_map<int,int> mp;
            
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                int count=0;
                dfs(i,adj,visited,count);
                mp[count]++;
                
            }
            
            
        }
        
        long long ans=0;
        for(auto it=mp.begin();it != mp.end();it++)
        {
            
            long long size = it->first;
            int freq = it->second;
            
            ans += (n-size)*size*freq;
            
            
            
        }
        
        
        return ans/2;
        
    }
};