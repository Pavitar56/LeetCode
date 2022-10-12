class Solution {
public:
    
    vector<int> dRow = {0,0,1,-1};
    vector<int> dCol = {1,-1,0,0};
    
    
    void dfs(vector<vector<int>>& grid,int row,int col,int &currMax)
    {
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        
        if(row < 0 || row >= numRows || col < 0 || col >=numCols)
        {
            return;
        }
        
        if(grid[row][col] == 0)
        {
            return;
        }
        
        if(grid[row][col] == -1)
        {
            return;
        }
        
        grid[row][col] = -1;
        currMax++;
        
        for(int i=0;i<4 ;i++)
        {
            dfs(grid,row + dRow[i],col + dCol[i],currMax);
        }
        
        return ;
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    int currMax = 0;
                    dfs(grid,i,j,currMax);
                
                    ans=max(ans,currMax);
                }
                
                
                
            }
            
        }
        
        
        
        return ans;
        
        
        
    }
};