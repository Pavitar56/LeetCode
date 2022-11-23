class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int pos0 = 0;
        int pos2 = nums.size() - 1;
        
        int curr = 0;
        
        while(curr <= pos2)
        {
            
            if(nums[curr] == 0)
            {
                swap(nums[curr],nums[pos0]);
                pos0++;
                if(nums[curr] == 0) //imp
                {
                    curr++;
                }
                continue;
            }
            else if(nums[curr] == 2)
            {
                swap(nums[curr],nums[pos2]);
                pos2--;
                continue;
            }
            
            curr++;
            
        }
        
        
        
    }
};