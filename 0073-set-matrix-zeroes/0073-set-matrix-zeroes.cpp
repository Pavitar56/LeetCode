class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int columns = matrix[0].size();        
        
//         for(int i=0;i<rows;i++)
//         {
//             for(int j=0;j<columns;j++)
//             {
                
//                 if(matrix[i][j] == 0)
//                 {
                    
//                     //travelling ith row
                    
//                     for(int k = 0 ;k<columns;k++)
//                     {
//                         if(matrix[i][k] !=0)      //tagging every non zero element in that row
//                         {
//                             matrix[i][k] = INT_MAX;   
//                         }
//                     }
                    
                    
//                     //travelling jth column
                    
//                     for(int k=0;k<rows;k++)
//                     {
//                         if(matrix[k][j] != 0)   //tagging every non zero element in that column
//                         {
//                             matrix[k][j] = INT_MAX;
//                         }
//                     }
//                 }
                  
//             }
//         }
        
//         //replacing all tagged elements with 0
//         for(int i=0;i<rows;i++)
//         {
//             for(int j=0;j<columns;j++)
//             {
//                 if(matrix[i][j] == INT_MAX)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
            
//         }
        
        bool firstRow = false;  // do we need to set first row zero
        bool firstCol = false;  // do we need to ser first col zero
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i==0)
                    {
                        firstRow = true;
                    }
                    
                    if(j==0)
                    {
                        firstCol = true;
                    }
                    
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                
            }
        }
        
        ///setting rows to 0
        for(int i = 1;i<rows;i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j=1;j<columns;j++)
                {
                    matrix[i][j]=0;
                }
         
            }
        }
        
        //setting columns to 0
        for(int j=1;j<columns;j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i=1;i<rows;i++)
                {
                    matrix[i][j] = 0;
                
                }
            }
            
        }
        
  
        //specail check for first row and first column
        if(firstRow == true)
        {
            for(int j=0;j<columns;j++)
            {
                matrix[0][j] = 0;
            }
             
        }
        
        if(firstCol == true)
        {
            for(int i=0;i<rows;i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        return;
        
        
        
    }
};