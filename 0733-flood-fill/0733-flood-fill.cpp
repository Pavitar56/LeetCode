class Solution {
public:
    
    vector<int> drow = {0,0,1,-1};
    vector<int> dcol = {1,-1,0,0};
    
    void dfs(vector<vector<int>>& image,int row,int col,int color,int initialColor)
    {
        int numRows= image.size();
        int numCols=image[0].size();
        
        if(row < 0 || row >= numRows || col < 0 || col >= numCols )
        {
            return;
        }
        
        if(image[row][col] != initialColor)
        {
            return;
        }
        
        if(image[row][col] == color)
        {
            return;
        }
        
        image[row][col] = color;
        
        for(int i=0;i<4;i++)
        {
           
            dfs(image,row+drow[i],col+dcol[i],color,initialColor);
        }
        
        
        
    }
    
    
    
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        
        int initialColor = image[sr][sc];
        
        dfs(image,sr,sc,color,initialColor);
        
        return image;
        
        
    }
};