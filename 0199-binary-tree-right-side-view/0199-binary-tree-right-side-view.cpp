class Solution {
public:
    
    int lower_bound(vector<int> &nums,int target)
    {
        int start = 0;
        int end = nums.size()-1;
        
        while(start<end)
        {
            int mid =  start + (end-start)/2;
            
            if(target <= nums[mid])
            {
                end = mid;
            }
            else
            {
                start =mid+1;
            }
            
            
        }
        
        if(nums[end] != target)
        {
            return -1;
        }
        
        
        return end;
    }
    
    int upper_bound(vector<int> &nums,int target)
    {
        
        int start =0;
        int end = nums.size()-1;
        
        while(start<end)
        {
            int mid = start + (end-start)/2;
            
            if(target >= nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }

        }
        
        if(nums[end] == target)
        {
            return end;
        }
        
        if(end == 0 && nums[end] != target)
        {
            return -1;
        }
        
        if(nums[end - 1] != target)
        {
            return -1;
        }
        return end - 1;
        
    }
    
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        if(nums.size()==0)
        {
            return {-1,-1};
        }
        
        return {lower_bound(nums,target) , upper_bound(nums,target) };
        
        
        
    }
};