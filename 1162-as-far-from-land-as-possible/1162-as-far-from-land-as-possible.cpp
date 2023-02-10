class Solution {
public:
    
    int bfs(vector<vector<int>> &grid,int sRow,int sCol)
    {
        int n = grid.size();
        vector<int> dRow = {-1,0,1,0};
        vector<int> dCol = {0,1,0,-1};
        int distance = INT_MAX;
        
        
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        //{{row,col},dist}
        queue<pair<pair<int,int>,int>> q;
        q.push({{sRow,sCol},0});
        visited[sRow][sCol] = 1;
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            if(grid[row][col] == 1)
            {
                distance = dis;
                break;
            }
            
            for(int i=0;i<4;i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                int nDis = dis + 1;
                
                
                if(nRow >=0 && nRow < n && nCol >= 0 && nCol < n && visited[nRow][nCol] == 0)
                {
                    q.push({{nRow,nCol},nDis});
                    visited[nRow][nCol] = 1;
                }
                
                
            }
            
        }
        
        return distance;
        
        
        
        
    }
    
    
    int maxDistance(vector<vector<int>>& grid) {
        
//         int ans = -1;
//         for(int i=0;i<grid.size();i++)
//         {
//             for(int j=0;j<grid[0].size();j++)
//             {
//                 if(grid[i][j] == 0)
//                 {
//                     int temp = bfs(grid,i,j);
                    
//                     if(temp == INT_MAX)
//                     {
//                         temp = -1;
//                     }
//                     ans = max(ans,temp);
//                 }
//             }
//         }
        
         int ans = -1;
        int n = grid.size();
        vector<int> dRow = {-1,0,1,0};
        vector<int> dCol = {0,1,0,-1};
        
        
        
         //{{row,col},dist}
        queue<pair<pair<int,int>,int>> q;
         
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }
        
        
      
        
       
        
       
        
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            
            for(int i=0;i<4;i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                int nDis = dis + 1;
                
                
                if(nRow >=0 && nRow < n && nCol >= 0 && nCol < n && visited[nRow][nCol] == 0)
                {
                    
                    if(grid[nRow][nCol] == 0)
                    {
                        ans = max(ans,nDis);
                        q.push({{nRow,nCol},nDis});
                        visited[nRow][nCol] = 1;
                    }
                    
                    
                }
                
                
            }
            
        }
        
        return ans;
        
    }
};