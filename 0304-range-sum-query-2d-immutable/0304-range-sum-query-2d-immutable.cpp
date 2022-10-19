// class NumMatrix {
// public:
//     vector<vector<int>> preSum;   //preSum[i][j] = sum of matrix[i][0] to matrix[i][j-1]
    
//     NumMatrix(vector<vector<int>>& matrix) 
//     {
        
//         for(int i=0;i<matrix.size();i++)
//         {
//             preSum.push_back({});
//             int rowSum = 0;
//             for(int j=0; j<=matrix[0].size();j++)
//             {
                
//                 if(j==0)
//                 {
//                     preSum[i].push_back(0);
//                     continue;
//                 }
//                 rowSum +=matrix[i][j-1];
                
//                 preSum[i].push_back(rowSum);
                
                
//             }
//         }
        
        
        
        
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) 
//     {
//         int ans=0;
//         for(int i=row1;i<=row2;i++)
//         {
//             ans += preSum[i][col2+1] - preSum[i][col1]; 
//         }
        
//         return ans;
        
        
        
        
//     }
// };

class NumMatrix 
{
private:
    int row, col;
    vector<vector<int>> sums;
public:
    
    NumMatrix(vector<vector<int>> &matrix) 
    {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) 
        {
            for(int j=1; j<=col; j++) 
            {
                sums[i][j] = matrix[i-1][j-1] + 
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */