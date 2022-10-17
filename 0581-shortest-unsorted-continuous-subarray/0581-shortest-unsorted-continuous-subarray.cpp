class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        
        vector<int> sortedVec(nums);
        
        sort(sortedVec.begin(),sortedVec.end());
        
        int i=0;
        int j= nums.size()-1;
        
        while(i<nums.size() && nums[i] == sortedVec[i])
        {
            i++;
        }
        
        while(j>=0 && nums[j] == sortedVec[j])
        {
            j--;
        }
        
        if((j-i+1) <= 0)
        {
            return 0;
        }
        
        return j-i+1;
    }
};