class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& graph,vector<int> &visited,vector<int> &currPath,
             vector<vector<int>> &ans)
    {
        if(visited[node])
        {
            return;
        }
        
        
        visited[node] = 1;
        
        currPath.push_back(node);
        
        if(node == (graph.size()-1)){
            ans.push_back(currPath);
        }
        else{
            for(int i=0;i<graph[node].size();i++)
            {
                dfs(graph[node][i],graph,visited,currPath,ans);
            }
        }
        
        currPath.pop_back();
        visited[node] = 0;
        return;
        
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        
        vector<int> visited(graph.size(),0);
        
        
        vector<int> currPath;
        vector<vector<int>> ans;
        
        dfs(0,graph,visited,currPath,ans);
        
        return ans;
        
        
        
    }
};