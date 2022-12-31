class Solution {
public:
    int ans = 0;
    
    vector<int> dRow ={-1,0,1,0};
    vector<int> dCol ={0,1,0,-1};
    
    void dfs(vector<vector<int>>& grid,int currRow,int currCol,int endRow,int endCol,
             vector<vector<int>> &visited)
    {
        if(visited[currRow][currCol] == 1)
        {
            return;
        }
        
        if(currRow == endRow && currCol == endCol)
        {
            bool flag = true;
            
            visited[endRow][endCol] = 1;
            for(int i=0;i<visited.size();i++)
            {
                for(int j=0;j<visited[i].size();j++)
                {
                    if(visited[i][j] == 0 && grid[i][j] != -1)
                    {
                        flag =false;
                        break;
                    }
                }
            }
            
            if(flag == true)
            {
                ans++;
            }
            
            visited[endRow][endCol] = 0;
            return;
            
        }
        
        
        
        visited[currRow][currCol] = 1;
        
        for(int i=0;i<4;i++)
        {
            int nRow = currRow + dRow[i];
            int nCol = currCol + dCol[i];
            
            
            if(nRow >=0 && nRow < grid.size() && nCol >=0 && nCol < grid[0].size() && visited[nRow][nCol] == 0)
            {
                if(grid[nRow][nCol] != -1)
                {
                    dfs(grid,nRow,nCol,endRow,endCol,visited);
                }
                
            }
        }
        
        visited[currRow][currCol] = 0;
        
        return;
 
    }
    
    
    
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int startRow,endRow,startCol,endCol;
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    startRow = i;
                    startCol = j;
                }
                else if(grid[i][j] == 2)
                {
                    endRow = i;
                    endCol = j;
                }
            }
        }
        
        
        dfs(grid,startRow,startCol,endRow,endCol,visited);
        
        
        
        
        return ans;
        
        
        
        
        
        
        
    }
};