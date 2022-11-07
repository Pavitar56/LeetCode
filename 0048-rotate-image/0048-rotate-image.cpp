class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        
        // complement of matrix 
        int m = matrix.size();
        for(int i=0; i<m; i++) 
        {
            for(int j=i; j<m; j++) 
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<m; i++) 
        {
		// 2 Pointer approach :  just like we do in 1D array we take left and right pointers
		// and swap the values and then make those pointers intersect at some point.
            int left = 0, right = m-1;
            
            while(left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                ++left;
                --right;
            }
        }
        
    }
};