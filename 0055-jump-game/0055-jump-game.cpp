class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int minJumps = 0;
        
        for(int i = nums.size() - 2;i>=0;i--)
        {
            minJumps++;
            
            if(nums[i] >= minJumps)
            {
                minJumps = 0;
            }
            
            
        }
        
        if(minJumps == 0)
        {
            return true;
        }
        
        return false;
    }
};