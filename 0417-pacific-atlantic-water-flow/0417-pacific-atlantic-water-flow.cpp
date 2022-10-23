class Solution {
public:
    
    int m;
    int n;
    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};
    
    
    bool atlantic(vector<vector<int>> &heights,int row,int col,int prev)
    {
        if(row >= m || col >= n)
        {
            return true;
        }
        
        if(row < 0 || col < 0)
        {
            return false;
        }
        
        if(heights[row][col] > prev)
        {
            return false;
        }
        
        if(heights[row][col] == -1)
        {
            return false;
        }
        
        for(int i=0;i<4;i++)
        {
            
            int temp = heights[row][col];
            heights[row][col] = -1;
            
            bool possible = atlantic(heights, row + drow[i] , col + dcol[i] ,temp);
            
            heights[row][col] = temp; 
            
            
            if(possible == true)
            {
                return true;
            }
        }
        
        
        return false;
    }
    
    bool pacific(vector<vector<int>> &heights,int row,int col,int prev)
    {
        if(row < 0 || col < 0)
        {
            return true;
        }
        
        if(row >= m || col >= n)
        {
            return false;
        }
        
        if(heights[row][col] > prev)
        {
            return false;
        }
        
        if(heights[row][col] == -1)
        {
            return false;
        }
        
        for(int i=0;i<4;i++)
        {
            
            int temp = heights[row][col];
            heights[row][col] = -1;
            
            bool possible = pacific(heights, row + drow[i] , col + dcol[i] ,temp);
            
            heights[row][col] = temp; 
            
            
            if(possible == true)
            {
                return true;
            }
        }
        
        
        return false;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {   
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {  
                bool Reach_Atlantic = atlantic(heights,i,j,INT_MAX);
                
                if(Reach_Atlantic == false)
                {
                    continue;
                }
                
                bool Reach_Pacific = pacific(heights,i,j,INT_MAX);
                
                if(Reach_Atlantic == true && Reach_Pacific == true)
                {
                    ans.push_back({i,j});
                }
            }
        }
        
       
        return ans;
    }
};