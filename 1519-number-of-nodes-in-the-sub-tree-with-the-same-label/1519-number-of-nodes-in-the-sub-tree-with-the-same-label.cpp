class Solution {
public:
    
    
    vector<int> dfs(int n,int curr,vector<vector<int>> &adj,vector<int> &visited,string &labels,vector<int> &ans)
    {
        
        visited[curr] = 1;
        vector<int> freq(26,0);
        freq[labels[curr]-'a']++;
        
        for(int i=0;i<adj[curr].size();i++)
        {
            int nNode = adj[curr][i];
            if(visited[nNode])
            {
                continue;
            }
            
            vector<int> temp = dfs(n,nNode,adj,visited,labels,ans);
            for(int j=0;j<temp.size();j++)
            {
                freq[j] += temp[j];
            }
        }
        
        ans[curr] = freq[labels[curr]-'a'];
        
        return freq;
        
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        
        vector<vector<int>> adj(n,vector<int>());
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        vector<int> visited(n,0);
        
        vector<int> ans(n,0);
        
        dfs(n,0,adj,visited,labels,ans);
        
        return ans;
        
    }
};