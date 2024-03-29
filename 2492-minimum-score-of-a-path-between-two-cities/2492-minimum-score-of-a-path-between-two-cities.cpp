class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
        // Storing graph in a adjacency list
        vector<vector<int>> adj[n+1];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        // making a visited array for keep tracking of all the cities (we have visited or not)
        // n = number of cities
        vector<bool> vis(n+1,false);
        vis[1] = true;                                  // mark source node as a visited city
        
        // BFS
        queue<int> q;
        q.push(1);

        while(!q.empty())   ///getting all connected components from 1 
        {
            int node = q.front();
            q.pop();

            for(auto &it : adj[node])
            {
                if(!vis[it[0]])
                {
                    vis[it[0]] = true;
                    q.push(it[0]);
                }
            }
        }


        // Computing minimum distance from city 1 to n
        int ans = INT_MAX;
        for(int i=0;i<roads.size();i++)
        {
            // minimum possible score out of all available paths
            // if src and dest both are visited cities then try to make this our ans
            if(vis[roads[i][0]] && vis[roads[i][1]])
            {
                ans = min(ans,roads[i][2]);
            }
        }

        return ans;
    }
};