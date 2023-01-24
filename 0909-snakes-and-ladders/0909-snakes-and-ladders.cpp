class Solution {
public:
    
    int solve(vector<vector<int>>& board,int curr,int r,int c,vector<int> visited)
    {
        int n = board.size();
        int n_sq = n * n;
       
        if(curr > n_sq)
        {
            return INT_MAX;
        }
        //cout<<r<<" "<<c<<endl;
        if(curr == n_sq)
        {
            return 0;
        }
        
        
        visited[curr] = 1;
        if(board[r][c] != -1)
        {
            curr = board[r][c];
        }
        
        int minimum = INT_MAX;
        
        for(int i=1;i<=6;i++)
        {
            int newCurr = curr + i;
            int newR;
            int newC;
            
            if(newCurr <= n_sq && visited[newCurr]==0)
            {
            
                if((newCurr % n) == 0)
                {

                    newR = (newCurr / n) - 1;

                    if((newR%2) == 0)
                    {
                        newC = n-1;
                    }
                    else
                    {
                        newC = 0;
                    }

                }
                else
                {
                    newR = newCurr/n;

                    if((newR%2) == 0)
                    {
                        newC = (newCurr%n)-1;
                    }
                    else
                    {
                        newC = n - (newCurr%n);
                    }
                }


                int temp = solve(board,newCurr,newR,newC,visited);
                cout<<temp<<endl;
                minimum = min(temp,minimum);
            }
        }
        visited[curr] = 0;
        if(minimum == INT_MAX)
        {
            return INT_MAX;
        }
        
        
        return minimum+1;
        
    }
    
    
    
    
    pair<int,int> coordinates(int newCurr,int n,int n_sq)
    {
        pair<int,int> p;
        int newR;
        int newC;
        if(newCurr <= n_sq )
        {
            
            if((newCurr % n) == 0)
            {

                newR = (newCurr / n) - 1;

                if((newR%2) == 0)
                {
                    newC = n-1;
                }
                else
                {
                    newC = 0;
                }

            }
            else
            {
                newR = newCurr/n;

                if((newR%2) == 0)
                {
                    newC = (newCurr%n)-1;
                }
                else
                {
                    newC = n - (newCurr%n);
                }
            }
        }
        p.first = newR;
        p.second = newC;
        return p;

    }
    
    
    
    
    
    
    
    int snakesAndLadders(vector<vector<int>>& board) {
//         reverse(board.begin(),board.end());
//         //cout<<board[2][1];
        
//         vector<int> visited(board.size()*board.size() + 1,0);
//         int ans = solve(board,1,0,0,visited);
        
//         if(ans == INT_MAX)
//         {
//             return -1;
//         }
//         return ans;
        
        int n = board.size();
        int n_sq = n * n;
        
        reverse(board.begin(),board.end());
        vector<int> visited(n_sq+1,0);
        
        queue<pair<int,int>> q;
        q.push({1,0});
        
        
        while(!q.empty())
        {
            
            int curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(curr == n_sq)
            {
                return steps;
            }
            
            for(int i=1;i<=6;i++)
            {
                int newCurr = curr+i;
                if(newCurr > n_sq)
                {
                    break;
                }
                
                pair<int,int> p = coordinates(newCurr,n,n_sq);
                
                int r = p.first;
                int c = p.second;
                
                if(board[r][c] != -1)
                {
                    newCurr = board[r][c];
                }
                
                pair<int,int> p2 = coordinates(newCurr,n,n_sq);
                
                r = p2.first;
                c = p2.second;
                if(visited[newCurr] == 0)
                {
                    q.push({newCurr,steps+1});
                    visited[newCurr] = 1;
                }
            }
            
   
        }
        
        return -1;
    }
};