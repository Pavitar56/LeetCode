class Solution {
public:
    
    bool solve(vector<vector<char>> &board, string &word, int i, int j, int k)
    {
        
        int n = board.size();
        int m = board[0].size();
        
        if(i < 0 or i >= n or j < 0 or j >= m) {
            return false;
        }
        
        if(board[i][j] == '$') 
        {
            return false;
        }
        
        if(board[i][j] != word[k])
        {
            return false;
        }
        
        if(k == word.size() - 1 && board[i][j] == word[k])
        {
            return true;
        }
        
        char ch = board[i][j];
        
        board[i][j] = '$';
        
        //Explore
        
        
        int op1 = solve(board, word, i+1, j , k+1);
        int op2 = solve(board, word, i-1, j , k+1);
        int op3 = solve(board, word, i, j+1 , k+1);
        int op4 = solve(board, word, i, j-1 , k+1);
        
        board[i][j] = ch;
        
        return op1 or op2 or op3 or op4;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                if(board[i][j] == word[0]) 
                {
                    bool ans = solve(board, word, i, j, 0);
                    if(ans)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};