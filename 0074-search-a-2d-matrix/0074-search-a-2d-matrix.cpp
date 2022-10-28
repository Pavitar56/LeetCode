class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(matrix[i][n-1] == target)
            {
                return true;
            }
            else if(matrix[i][n-1] > target)
            {
                
                int start = 0;
                int end = n-1;
                
                while(start<=end)
                {
                    int mid = start + (end-start)/2;
                
                    if(target == matrix[i][mid])
                    {
                        return true;
                    }
                    else if(target < matrix[i][mid])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        start = mid+1;
                    }
                    
                    
                }
                
                return false;
                
            }
            
        }
        
        return false;
        
    }
};