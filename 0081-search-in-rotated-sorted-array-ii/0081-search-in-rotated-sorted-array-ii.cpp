class Solution {
public:
   bool binarySearch(vector<int> &nums,int start,int end,int &target)
    {
        while(start<=end)
        {
            int mid=(start+end)/2;
            
            if(nums[mid]==target)
            {
                return true;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return false;
        
        
    }
    
    bool search(vector<int>& nums, int target)
    {
        int i=0;
        while((i+1)<nums.size() && nums[i]<=nums[i+1])
        {
            i++;
            
        }
        
        bool ans1 = binarySearch(nums,0,i,target);
        bool ans2 =binarySearch(nums,i+1,nums.size()-1,target);
        
        return ans1|| ans2 ;
    }
};