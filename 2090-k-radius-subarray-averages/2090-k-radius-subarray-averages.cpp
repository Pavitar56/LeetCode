class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long int> preSum(nums.size(),0);
        preSum[0] = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            preSum[i] = preSum[i-1] + nums[i];  
        }
        
        vector<int> ans(nums.size());
        
        for(int i=0;i<nums.size();i++)
        {
            int start = i - k;
            int end = i + k;
            
            if(start < 0 || end >= nums.size())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = (preSum[end] - preSum[start] + nums[start])/(2*k + 1);
                
                
            }
            
            
            
        }
        
        return ans;
        
    }
};