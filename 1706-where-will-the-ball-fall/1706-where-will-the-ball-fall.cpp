class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> ans(n,0);
        
        for(int j = 0;j < n;j++)
        {
            int sr = 0;
            int sc = j;
            
            for(int count = 1;count <= m;count++)
            {
                if(sc == 0 && grid[sr][sc] == -1)
                {
                    ans[j] = -1;
                    break;
                }
                
                if(sc == n-1 && grid[sr][sc] == 1)
                {
                    ans[j] = -1;
                    break;
                }
                
                
                if(sc <= n-2)
                {
                    if(grid[sr][sc] == 1 && grid[sr][sc+1] == -1)
                    {
                        ans[j] = -1;
                        break;
                    }
                }
                
                if(sc > 0)
                {
                    if(grid[sr][sc] == -1 && grid[sr][sc-1] == 1)
                    {
                        ans[j] = -1;
                        break;
                    }
                }
                
                if(sr == m-1)
                {
                    if(grid[sr][sc] == -1)
                    {
                        ans[j] = sc - 1;
                    }
                    else
                    {
                        ans[j] = sc + 1;
                    }
                    
                    break;
                }
                
                if(grid[sr][sc] == 1)
                {
                    sr++;
                    sc++;
                }
                else
                {
                    sr++;
                    sc--;
                }
                
            }
        
        }
        
        return ans;
        
        
        
        
        
    }
};