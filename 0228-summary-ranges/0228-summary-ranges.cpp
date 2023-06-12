class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;
        if(nums.size() == 0)
        {
            return ans;
        }
        else if(nums.size() == 1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        
        int start = 0;
        int prev = nums[0];
        int curr = 1;
        
        while(curr < nums.size())
        {
            if(nums[curr] == prev + 1)
            {
                prev = nums[curr];
            }
            else
            {
                if(nums[start] == prev)
                {
                    ans.push_back(to_string(prev));
                }
                else
                {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(prev));
                }
                
                start = curr;
                prev = nums[curr];
                
            }
            curr++;
            
        }
         if(nums[start] == prev)
        {
            ans.push_back(to_string(prev));
        }
        else
        {
            ans.push_back(to_string(nums[start]) + "->" + to_string(prev));
        }
        return ans;
    }
};