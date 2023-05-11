class Solution {
public:
    
    int solve(vector<int> &nums1,vector<int> &nums2,int idx,int idx2,vector<vector<int>> &dp)
    {
        if(idx < 0 || idx2 < 0)
        {
            return 0;
        }
        
        if(dp[idx][idx2] != -1)
        {
            return dp[idx][idx2];
        }
        
        int count = 0;
        
        if(nums1[idx] == nums2[idx2])
        {
            count = 1 + solve(nums1,nums2,idx-1,idx2-1,dp);
        }
        else
        {
            count += max(solve(nums1,nums2,idx,idx2-1,dp),solve(nums1,nums2,idx-1,idx2,dp));
        }
        
        
        
        return dp[idx][idx2] = count;
        
    }
    
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return solve(nums1,nums2,nums1.size()-1,nums2.size()-1,dp);
        
        
    }
};