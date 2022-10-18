class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        set<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int curr = nums[i];
            
            int j=i+1;
            int k=nums.size()-1;
            int target = 0 - nums[i];
            while(j<k)
            {
                if((nums[j] + nums[k]) == target)
                {
                    ans.insert({curr,nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if((nums[j] + nums[k])>target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        
        vector<vector<int>> finalans;
        
        for(auto it = ans.begin();it!=ans.end();it++)
        {
            finalans.push_back(*it);
        }
        
        return finalans;
    }
};