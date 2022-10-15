class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        
//         vector<int> prefix(nums.size(),1);
//         vector<int> suffix(nums.size(),1);
        
        
       
        
//         for(int i=1;i<nums.size();i++)
//         {
//             prefix[i] = prefix[i-1] * nums[i-1];
            
//         }
        
//         for(int i=nums.size() - 2 ;i>=0;i--)
//         {
//             suffix[i] = suffix[i+1] * nums[i+1];
            
//         }
        
//         vector<int> ans(nums.size(),1);
        
//         for(int i=0;i<nums.size();i++)
//         {
            
//             ans[i] = prefix[i] * suffix[i];
//         }
        
//         return ans;
        
        vector<int> ans(nums.size(),1);
        int pre = nums[0];
        int suff= nums[nums.size()-1];
        
        for(int i=1;i<nums.size();i++)
        {
            ans[i] *= pre;
            pre = pre *nums[i];
        }
        
        for(int i=nums.size() - 2;i>=0;i--)
        {
            ans[i] *= suff;
            suff = suff *nums[i];
        }
        return ans;
    }
};