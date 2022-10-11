class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            nums.push_back(nums[i]);
        }
        
        vector<int> ans(len ,-1);
        
        for(int i=0;i<len;i++)
        {
            int nextGreater = -1;
            for(int j = i+1 ; j< len + i ;j++)
            {
                if(nums[j] > nums[i])
                {
                    nextGreater = nums[j];
                    break;
                }
                
            }
            
            ans[i] = nextGreater;
        }
        
        
        return ans;
    }
};