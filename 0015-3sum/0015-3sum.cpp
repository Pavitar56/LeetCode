class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {                              //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            int curr = nums[i];
            
            int j=i+1;
            int k=nums.size()-1;
            int target = 0 - nums[i];
            while(j<k)
            {
                if((nums[j] + nums[k]) == target)
                {
                    ans.push_back({curr,nums[j],nums[k]});
                    int last_j_occurance= nums[j];
                    int last_k_occurance = nums[k];
                    while(j<k && nums[j] == last_j_occurance) //as we dont want repeatition
                    {
                        j++;
                    }
                    
                    while(k>j && nums[k] ==last_k_occurance)  //as we dont want repeatition
                    {
                        k--;
                    }
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
        
        
        
        return ans;
    }
};