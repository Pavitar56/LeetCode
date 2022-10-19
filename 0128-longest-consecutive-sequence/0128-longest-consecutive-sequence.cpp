class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());

        
        int maxSoFar = 1;
        int currMax = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] +1)
            {
                currMax++;
            }
            else if(nums[i] == nums[i-1])
            {
                continue;
            }
            else
            {
                currMax = 1;
            }
            
            maxSoFar = max(currMax,maxSoFar);
            
        }
        
        return maxSoFar;
        
    }
};