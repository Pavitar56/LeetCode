class Solution {
public:
    
    vector<bool> vis;
    int dfs(vector<vector<int>> &graph,vector<bool>& hasApple,int node,int cost)
    {
        if(vis[node])
            return 0;
        
        vis[node]=true;
        int children_cost=0;
        
        for(auto x:graph[node])
            children_cost+=dfs(graph,hasApple,x,2);
        
        if(children_cost==0 && hasApple[node]==false)
            return 0;
        
        return (children_cost+cost);
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int>> graph(n);
        vis=vector<bool>(n,false);
        
        for(auto &x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        return dfs(graph,hasApple,0,0);
    }
    
};