class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        
        int allXor = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            allXor ^= nums[i]; 
        }
        
        return allXor;
    }
};