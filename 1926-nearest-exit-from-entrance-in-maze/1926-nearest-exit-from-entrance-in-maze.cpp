class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int tRows = maze.size();
        int tCols = maze[0].size();
        
        vector<vector<int>> visited(tRows,vector<int>(tCols,0));
        
        vector<int> dRow = {-1,0,1,0};
        vector<int> dCol = {0,1,0,-1};
        
        int eRow = entrance[0];
        int eCol = entrance[1];
        
        //{{row,col},dist}
        queue<pair<pair<int,int>,int>> q;
        q.push({{eRow,eCol},0});
        visited[eRow][eCol] = 1;
        
        while(!q.empty())
        {
            int row  = q.front().first.first;
            int col = q.front().first.second;
            
            int steps = q.front().second;
            
            if(row != eRow || col != eCol)
            {
                if(row == 0 || col == 0 || col == tCols-1 || row == tRows - 1)
                {
                    return steps;
                }
                
            }
            
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                int nSteps = steps + 1;
                
                if(nRow >=0 && nRow < tRows && nCol >= 0 && nCol < tCols)
                {
                    if(!visited[nRow][nCol] && maze[nRow][nCol] == '.')
                    {
                        q.push({{nRow,nCol},nSteps});
                        visited[nRow][nCol] = 1;
                       // cout<<nRow<<" "<<nCol<<endl;
                    }
                }
                
                
            }
            
            
            
            
        }
        
        return -1;
        
    }
};