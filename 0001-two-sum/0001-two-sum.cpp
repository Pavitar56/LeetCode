class Solution {
public:
    
    
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans(2);
        unordered_map<int,int> indexes;
        
        
        for(int i=0;i<nums.size();i++)
        {
            int numToFind=target-nums[i];
            
            if(indexes.count(numToFind)>0)
            {
                ans[0]=i;
                ans[1]=indexes[numToFind];
                return ans;
            }
            indexes[nums[i]]=i;
            
        }
        
        return ans;
        
    }
};