class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> ans(2);
        unordered_map<int,int> freq;
        
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]=freq[nums[i]]+1;
        }
        
        for(int i=1;i<=nums.size();i++)
        {
            if(freq[i]>1)
            {
                ans[0]=i;
            }
            if(freq[i]==0)
            {
                ans[1]=i;
            }
        }
        
        return ans;
    }
};