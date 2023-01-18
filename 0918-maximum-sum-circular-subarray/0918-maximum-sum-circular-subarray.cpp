class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maximum = nums[0];
        int minimum = nums[0];
        
        int curMax = nums[0];
        int curMin = nums[0];
        
        int total = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            curMax = max(curMax + nums[i],nums[i]);
            curMin = min(curMin + nums[i],nums[i]);
            
            maximum = max(maximum,curMax);
            minimum = min(minimum,curMin);
            total += nums[i];
            
            
        }
        
        
        return maximum > 0 ? max(maximum,total - minimum):maximum;
        
        
    }
};