class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        
        int totalRows = mat.size();
        int totalCols = mat[0].size();
        
        
        vector<vector<int>> ans(totalRows,vector<int>(totalCols,INT_MAX));
        
        
        vector<vector<int>> visited(totalRows,vector<int>(totalCols,0));
        
        
        //{{row,col},step}
        
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int row=0; row < totalRows;row++)
        {
            for(int col=0;col<totalCols;col++)
            {
                if(mat[row][col] == 0)
                {
                    q.push({{row,col},0});
                    visited[row][col] = 1;
                   // ans[row][col] = 0;
                }
                
            }
        }
        
        
        vector<int> dRow = {-1,0,1,0};
        vector<int> dCol = {0,1,0,-1};
        
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            
            int steps = q.front().second;
            
            ans[row][col] = steps;
            
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                int nSteps = steps + 1;
                
                if(nRow >=0 && nRow < totalRows && nCol >=0 && nCol < totalCols)
                {
                    
                    if(!visited[nRow][nCol])
                    {
                        q.push({{nRow,nCol},nSteps});
                        visited[nRow][nCol] = 1;    
                    }
                    
                }
         
            }
                  
        }
        
        
        return ans;
        
        
    }
};