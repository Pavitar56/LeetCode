class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int pos0 = 0;
        int pos2 = nums.size() - 1;
        
        int start = 0;
        
        while(start <= pos2)
        {
            
            if(nums[start] == 0)
            {
                swap(nums[start],nums[pos0]);
                pos0++;
                if(nums[start] == 0)
                {
                    start++;
                }
                continue;
            }
            else if(nums[start] == 2)
            {
                swap(nums[start],nums[pos2]);
                pos2--;
                continue;
            }
            
            start++;
            
        }
        
        
        
    }
};