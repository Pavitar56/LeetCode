class Solution {
public:
    unordered_map<int,int> map ={{0,0},{1,3},{2,6}};
    
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                
                char num = board[i][j];
                //row check
                for(int k=0;k<9;k++)
                {
                    if(i == k)
                    {
                        continue;
                    }
                    if(board[k][j] == num)
                    {
                       
                        return false;
                    }
                       
                }
                
                //column check
                
                for(int k = 0;k<9;k++)
                {
                    if(j==k)
                    {
                        continue;
                    }
                    
                    if(board[i][k] == num)
                    {
                         
                        return false;
                    }
                }
                
                //grid check
                
                int startrow;
                int startcol;
                
                if(i%3 == 0)
                {
                    startrow = i;
                }
                else
                {
                    startrow= map[i/3];
                }
                
                if(j%3 == 0)
                {
                    startcol = j;
                }
                else
                {
                    startcol= map[j/3];
                }
                
                for(int m = startrow ; m < startrow + 3;m++)
                {
                    for(int n = startcol ; n<startcol + 3;n++)
                    {
                        if(m==i && n==j)
                        {
                            continue;
                        }
                        if(board[m][n] == num)
                        {
                            
                            return false;
                        }
                        
                    }
                }
                
            }
        }
        
        
        
        return true;
        
        
        
        
        
        
    }
};