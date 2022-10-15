class Solution {
public:
    int rob(vector<int>& nums) 
    {
//         vector<int> dp(nums.size(),0); //keeps track for maxloot till house[i] including ith house
        
        
//         for(int i=0;i<nums.size();i++)
//         {
//             int maximum = 0;
//             for(int j = i-2 ;j>=0;j--)
//             {
//                 maximum=max(maximum,dp[j]);
//             }
            
//             dp[i] = maximum + nums[i];
//         }
        
//         int maximum = dp[0];
//         for(int i=0;i<nums.size();i++)
//         {
//             maximum = max(dp[i],maximum);
//         }
        
//         return maximum;
        
        if(nums.size()==1)
            return nums[0];
        
        vector<int>dp(nums.size());
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        
        return dp[nums.size()-1];
        
        
        
        
        
    }
};