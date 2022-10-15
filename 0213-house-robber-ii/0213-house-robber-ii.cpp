class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 0)
        {
            return 0;
        }
        else if(nums.size() == 1)
        {
            return nums[0];
        }
        else if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        
        
        vector<int> dpWithoutLastEl(nums.size() - 1,0);
        
        dpWithoutLastEl[0] = nums[0];
        dpWithoutLastEl[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size() - 1;i++)
        {
            dpWithoutLastEl[i]=max(dpWithoutLastEl[i-1],dpWithoutLastEl[i-2]+nums[i]);
        }
        
        
        vector<int> dpWithoutFirstEl(nums.size()-1,0);
        
        dpWithoutFirstEl[0] = nums[1];
        dpWithoutFirstEl[1] = max(nums[1],nums[2]);
        
        for(int i=3;i<nums.size();i++)
        {
            dpWithoutFirstEl[i-1]= max(dpWithoutFirstEl[i-2],dpWithoutFirstEl[i-3] + nums[i]);
        }
        
        
        return max(dpWithoutLastEl[nums.size()-2] , dpWithoutFirstEl[nums.size()-2] );
        
    }
};