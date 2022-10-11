class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
//         int len=nums.size();
//         for(int i=0;i<len;i++)
//         {
//             nums.push_back(nums[i]);
//         }
        
//         vector<int> ans(len ,-1);
        
//         for(int i=0;i<len;i++)
//         {
//             int nextGreater = -1;
//             for(int j = i+1 ; j< len + i ;j++)
//             {
//                 if(nums[j] > nums[i])
//                 {
//                     nextGreater = nums[j];
//                     break;
//                 }
                
//             }
            
//             ans[i] = nextGreater;
//         }
        
        
//         return ans;
        
        stack<int> stk;
        
        for(int i=nums.size()- 1; i>=0 ;i--)
        {
            stk.push(nums[i]);
        }
        
        vector<int> ans(nums.size(),-1);
        
        for(int j = nums.size()-1 ;j>=0;j--)
        {
            while(!stk.empty() && stk.top() <= nums[j])
            {
                stk.pop();
            }
            
            if(stk.empty())
            {
                ans[j] = -1;
            }
            else
            {
                ans[j] = stk.top();
            }
            
            stk.push(nums[j]);
        
        }
        
        return ans;
    }
};