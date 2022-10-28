class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        
        int count=1;
        
        int sr=0,sc=0,er=n-1,ec=n-1;
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        while(count <= (n*n))
        {
            //right
            for(int i=sc;i<=ec;i++)
            {
                ans[sr][i]= count;
               
                count++;
            }
            
            sr++;
            
            //down
            for(int i=sr;i<=er;i++)
            {
                ans[i][ec] = count;
            
                count++;
            }
            
            ec--;
            
            //left
            for(int i=ec;i>=sc;i--)
            {
                ans[er][i] = count;
              
                count++;
            }
            
            er--;
            
            //up
            for(int i=er;i>=sr;i--)
            {
                ans[i][sc] = count;
                
                count++;
            }
            
            sc++;
        }
        
        return ans;
        
    }
};