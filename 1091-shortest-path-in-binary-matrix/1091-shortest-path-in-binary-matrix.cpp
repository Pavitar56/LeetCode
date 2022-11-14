class Solution {
public:
    
    
   
    
    
    
//     int dfs(vector<vector<int>>& grid,int i,int j)
//     {
//         int m=grid.size();
//         int n=grid[0].size();
        
//         if(i < 0 || i >= m || j < 0 || j >= n )
//         {
//             return INT_MAX-1;
//         }
        
//         if(grid[i][j] == 1)
//         {
//             return INT_MAX-1;
//         }
        
        
        
//         if(i == m-1 && j == n-1)
//         {
            
//             return 1;
//         }
        

        
        
//         grid[i][j] = 1;
        
//         int minimum = INT_MAX-1;
        
//         for(int k=0;k<8;k++)
//         {
//             minimum = min(minimum , dfs(grid,i+di[k],j+dj[k]));
//         }
        
//         grid[i][j] = 0;
    
        
//         return minimum + 1;
        
//     }
    
    
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        
//         int m=grid.size();
//         int n=grid[0].size();
        
        
//         vector<vector<int>> dp(m,vector<int>(n,-1));
        
//         if(grid[0][0] == 0 && grid[m-1][n-1] == 0)
//         {
//             int ans= dfs(grid,0,0);
            
//             return ans < INT_MAX-1 ? ans : -1;
            
//         }
        
//         return -1;
        
        
        if(grid[0][0] == 1)
        {
            return -1;
        }
        
         vector<int> dRow = {-1,-1,0,1,1,1,0,-1};
         vector<int> dCol = {0,1,1,1,0,-1,-1,-1};
        
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        
        vector<vector<int>> visited(totalRows,vector<int>(totalCols,0));
        
        //{{row,col},steps}
    
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        visited[0][0] = 1;
        
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            
            int steps = q.front().second;
            
            if(row == totalRows - 1 && col == totalCols - 1)
            {
                return steps;
            }
            q.pop();
            
            
            for(int i=0;i<8;i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                
                int nSteps = steps + 1;
                
                
                if(nRow >=0 && nRow < totalRows && nCol >= 0 && nCol < totalCols)
                {
                    if(!visited[nRow][nCol] && grid[nRow][nCol] == 0)
                    {
                        q.push({{nRow,nCol},nSteps});
                        visited[nRow][nCol] = 1;
                    }
                }
            }
            
        }
        
        
        
        return -1;
        
        
        
        
        
        
        
        
        
        
    }
};