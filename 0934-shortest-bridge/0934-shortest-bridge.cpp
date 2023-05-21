class Solution {
public:
    //TC= O(M*N)
    
    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};
    
    void dfs(vector<vector<int>>& grid,int row ,int col,int &totalRows,int &totalCols,                                        vector<vector<int>> &island)
    {
        
        if(row < 0 || row >= totalRows || col < 0 || col >= totalCols)
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
        island.push_back({row,col});
        
        for(int i=0;i<4;i++)
        {
            dfs(grid,row + drow[i],col+ dcol[i],totalRows,totalCols,island);
        }
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid)
    {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        
        vector<vector<int>> island1;
        vector<vector<int>> island2;
        
        int count = 1;
        
        for(int i=0;i < totalRows;i++)
        {
            for(int j=0;j<totalCols;j++)
            {
                if(grid[i][j] == 1)
                {
                    if(count == 1)
                    {
                        dfs(grid,i,j,totalRows,totalCols,island1);
                        count++;
                    }
                    else
                    {
                        dfs(grid,i,j,totalRows,totalCols,island2);
                    }
                }
            }
        }
        
        int minimum = INT_MAX;
        for(int i = 0 ; i<island1.size();i++)
        {
            for(int j = 0 ;j < island2.size();j++)
            {
                
                int distance = (abs(island2[j][1] - island1[i][1]) + abs(island2[j][0] - island1[i][0])) - 1;
                
                minimum = min(distance,minimum);
                
            }
        }
        
        
        return minimum;
    }
};