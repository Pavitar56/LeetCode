class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),0); //keeps track for maxloot till house[i] including ith house
        
        
        for(int i=0;i<nums.size();i++)
        {
            int maximum = 0;
            for(int j = i-2 ;j>=0;j--)
            {
                maximum=max(maximum,dp[j]);
            }
            
            dp[i] = maximum + nums[i];
        }
        
        int maximum = dp[0];
        for(int i=0;i<nums.size();i++)
        {
            maximum = max(dp[i],maximum);
        }
        
        return maximum;
        
        
        
        
        
    }
};