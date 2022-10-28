class Solution {
public:
    int jump(vector<int>& nums)
    {
        
//         vector<int> dp(nums.size(),0);
        
        
//         dp[0] = 0;
        
//         for(int i=1;i<nums.size();i++)
//         {
            
//             for(int j = i-1;j>=0;j--)
//             {
//                int minimum = INT_MAX;
//                if(nums[j] >= (i-j))
//                {
//                    minimum = min(minimum,dp[j]);
//                }
//                 if(minimum != INT_MAX)
//                 {
//                     dp[i] = minimum + 1;
//                 }
                
//             }
            
//             //cout<<dp[i]<<" ";
//         }
        
//         return dp[nums.size()-1];
        
        int n = nums.size();
        
        int jumps = 0;
        int maxReach = 0;
        int currReach = 0;
        
        for(int i=0; i<n-1; i++)
        {
            maxReach = max(maxReach, i+nums[i]);
            
            if(i==currReach)
            {
                jumps++;
                currReach = maxReach;
            }
            
        }
        
        return jumps;
    }
};