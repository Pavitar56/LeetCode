class Solution {
public:
    
    
    vector<int> di = {2,1,-1,-2,-2,-1,1,2};
    vector<int> dj = {1,2,2,1,-1,-2,-2,-1};
    
    
    double helper(int n,int k,int i,int j, vector<vector<vector<double>>> &dp)
    {
        
        if(i<0||j<0||i>=n||j>=n||k<0)
        {
            return 0;
        }
        
        
        if(k==0)
        {
            return 1;
        }
       
        if(dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        
        double choices=0;
        for(int m=0;m<8;m++)
        {
            
            choices += helper(n,k-1, i + di[m],j + dj[m],dp);
            
        }
        
        dp[i][j][k] = 0.125 * choices;
        
        return dp[i][j][k];
        
        
    }
    
    
    
    
    double knightProbability(int n, int k, int row, int column) 
    {
        
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        
       
      
        double probability = helper(n,k,row,column,dp);
        
        
        return probability;
        
        
    }
};