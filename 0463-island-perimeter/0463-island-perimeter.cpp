class Solution {
public:
    
    int count = 0;
    vector<int> di = {0,0,1,-1};
    vector<int> dj = {1,-1,0,0};
    
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        int rows=grid.size();
        int columns=grid[0].size();
        
        
        if(i<0 || i >= rows || j < 0 || j >= columns || grid[i][j] == '$' || grid[i][j] != 1)
        {
            return;
        }
        
        grid[i][j] = '$';
        
        if(j == (columns-1))
        {
            count++;
        }
        else if(grid[i][j+1] == 0)
        {
            count++;
        }
        
        if(j == 0)
        {
            count++;
        }
        else if(grid[i][j-1] == 0)
        {
            count++;
        }
        
        if(i == 0)
        {
            count++;
        }
        else if(grid[i-1][j] == 0)
        {
            count++;
        }
        
        if(i == rows-1)
        {
            count++;
        }
        else if(grid[i+1][j] == 0)
        {
            count++;
        }
        
        
        
        for(int k=0;k<4;k++)
        {
            dfs(grid,i+di[k],j+dj[k]);
        }
        
        
        
    }
    
    
    int islandPerimeter(vector<vector<int>>& grid)
    {
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j);
                   // cout<<count;
                }
                
                
            }
            
        }
        
        return count;
        
    }
};