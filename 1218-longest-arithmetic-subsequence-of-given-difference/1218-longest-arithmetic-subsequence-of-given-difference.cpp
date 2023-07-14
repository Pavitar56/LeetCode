class Solution {
public:
    
    int solve(vector<int> &v,int diff,int ind,int prev_ind,vector<vector<int>> &dp)
    {
        if(ind == v.size())
        {
            return 0;
        }
        
        if(dp[ind][prev_ind+1] != -1)
        {
            return dp[ind][prev_ind+1];
        }
        
        int take = 0;
        if(prev_ind == -1)
        {
            take = 1 + solve(v,diff,ind+1,ind,dp);
        }
        else if((v[ind] - v[prev_ind]) == diff)
        {
            take = 1 + solve(v,diff,ind+1,ind,dp);
        }
        
        
        int notTake = solve(v,diff,ind+1,prev_ind,dp);
       
        return dp[ind][prev_ind+1] = max(take,notTake);
        
    }
    
    
    int longestSubsequence(vector<int>& arr, int difference) {
        //vector<vector<int>> dp(arr.size(),vector<int>(arr.size()+1,-1));
        
       // return solve(arr,difference,0,-1,dp);
       
        int n = arr.size();
        unordered_map<int, int> dp; // Stores the maximum length at each index
        
        int ans = 1; // Initialize with the minimum length of 1
        
        for (int i = 0; i < n; i++) 
        {
            int num = arr[i];
            if (dp.find(num - difference) != dp.end()) 
            {
                dp[num] = dp[num - difference] + 1;
            } 
            else 
            {
                dp[num] = 1;
            }
            
            ans = max(ans, dp[num]);
        }
        
        return ans;
        
        
        
    }
};