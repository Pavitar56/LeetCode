class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int idx = -1;
        for(int i=nums.size()-1;i>=1;i--)
        {
            if(nums[i] > nums[i-1])
            {
                idx= i-1;
                break;
            }
            
            
        }
        
        if(idx == -1)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        
        int minimum=INT_MAX;
        int nxtIdx;
        for(int i=nums.size()-1;i>idx;i--)
        {
            if(nums[i] > nums[idx] && nums[i] < minimum)
            {
                minimum =nums[i];
                nxtIdx = i;
            }
            
        }
        
        swap(nums[idx],nums[nxtIdx]);
        
        sort(nums.begin() + idx +1,nums.end());
        
        
    }
};