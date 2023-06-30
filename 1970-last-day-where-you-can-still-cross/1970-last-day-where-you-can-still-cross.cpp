class Solution {
public:
    vector<int> dRow = {-1,0,1,0};
    vector<int> dCol = {0,1,0,-1};
    
    bool possible(int idx,int row,int col,vector<vector<int>> &cells)
    {
        
        vector<vector<int>> mat(row,vector<int>(col,0));
        for(int i=0;i<idx;i++)
        {
            mat[cells[i][0]][cells[i][1]] = 1;
        }
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        
        for(int i=0;i<col;i++)
        {
            if(mat[0][i] == 0)
            {
                q.push({0,i});
                vis[0][i] = 1;
            }
        }
        
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                
                if(nRow >= 0 && nRow < row && nCol >=0 && nCol < col && vis[nRow][nCol] == 0 && mat[nRow][nCol] == 0)
                {
                    if(nRow == row - 1)
                    {
                        return true;
                    }
                    
                    q.push({nRow,nCol});
                    vis[nRow][nCol] = 1;
                    
                }
                
            }
            
        }
        
        return false;
        
        
    }
    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        
        for(int i=0;i<cells.size();i++)
        {
            cells[i][0]--;
            cells[i][1]--;            
        }
        
        
        int start = 0;
        int end = cells.size()-1;
        
        
        int ans = 0;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(possible(mid,row,col,cells))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        
        return ans;
        
        
        
    }
};