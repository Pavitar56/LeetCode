class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int a=0;a<nums.size();a++)
        {
            if(a>0 && nums[a] == nums[a-1])
            {
                continue;
            }
            
            for(int b = a+1;b<nums.size();b++)
            {
                if(b>(a+1) && nums[b]==nums[b-1])
                {
                    continue;
                }
                
                long long int sum1 = nums[a]+nums[b];
                if(sum1> INT_MAX || sum1 <INT_MIN)
                {
                    continue;
                }
                
                int c = b+1;
                int d = nums.size() - 1;
                
                long long int sum2 = target - sum1;
                if(sum2 > INT_MAX || sum2 < INT_MIN)
                {
                    continue;
                }
                
                int target_find = target - nums[a] - nums[b];
                
                while(c<d)
                {
                    if((nums[c]+ nums[d]) == target_find)
                    {
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        
                        int last_left = nums[c];
                        
                        while(c<d && nums[c] == last_left)
                        {
                            c++;
                        }
                        int last_right = nums[d];
                        while(c<d && nums[d] == last_right)
                        {
                            d--;
                        }
                            
                    }
                    else if((nums[c] + nums[d]) < target_find)
                    {
                        c++;
                    }
                    else
                    {
                        d--;
                    }
                    
                    
                }
            
                
            }
            
        }
        
        return ans;
        
        
        
    }
};