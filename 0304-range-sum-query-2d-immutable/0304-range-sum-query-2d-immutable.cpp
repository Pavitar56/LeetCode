class NumMatrix {
public:
    vector<vector<int>> preSum;   //preSum[i][j] = sum of matrix[i][0] to matrix[i][j-1]
    
    NumMatrix(vector<vector<int>>& matrix) 
    {
        
        for(int i=0;i<matrix.size();i++)
        {
            preSum.push_back({});
            int rowSum = 0;
            for(int j=0; j<=matrix[0].size();j++)
            {
                
                if(j==0)
                {
                    preSum[i].push_back(0);
                    continue;
                }
                rowSum +=matrix[i][j-1];
                
                preSum[i].push_back(rowSum);
                
                
            }
        }
        
        
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int ans=0;
        for(int i=row1;i<=row2;i++)
        {
            ans += preSum[i][col2+1] - preSum[i][col1]; 
        }
        
        return ans;
        
        
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */