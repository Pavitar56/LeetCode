class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        
//         int maxSum=INT_MIN;
//         for(int i=0;i<nums.size();i++)
//         {
//             int sum=0;
            
//             for(int j=i;j<nums.size();j++)
//             {
//                 sum += nums[j];
//                 maxSum = max(sum,maxSum);
                
//             }
            
//         }
        
//         return maxSum;
        
//         vector<int> dp(nums.size(),0);
        
//         dp[0]= nums[0];
//         int maximum = nums[0]; 
        
        
//         for(int i=1;i<nums.size();i++)
//         {
//             dp[i] = max(dp[i-1] + nums[i],nums[i]);
//             maximum = max(dp[i],maximum);
            
//         }
        
//         return maximum;
        
        int prev =nums[0];
        int maximum = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            int curr = max(prev + nums[i],nums[i]);
            maximum = max(curr,maximum);
            prev= curr;
        }
        return maximum;
        
        
        
        
    }
};