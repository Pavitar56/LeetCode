// class Solution {
// public:
//     vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
//     {
//         sort(nums.begin(),nums.end());
        
//         vector<int> ans;
//         for(int i=0;i<queries.size();i++)
//         {
            
//             int q = queries[i];
            
//             int start = 0;
//             int count = 0;
//             int sum = 0;
            
//             while(start < nums.size() && (sum + nums[start]) <= q)
//             {
//                 sum += nums[start];
//                 start++;
//                 count++;
//             }
            
//             ans.push_back(count);
            
//         }
        
//         return ans;
        
        
//     }
// };

class Solution{
    public:
    int lowerbound(vector<int> &preSum,int target)
    {
        int start = 0;
        int end = preSum.size() - 1;
        
        while(start < end)
        {
            int mid = start + (end - start)/2;
            
            if(target <= preSum[mid])
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
            
            
        }
        
        if(end == 0 && preSum[end] > target) //this is when not found
        {
            return 0;
        }
        
        if(preSum[end] > target) //this is when found 1st element greater
        {
            return end;
        }
        
        return end+1; //this is when element == target..
        
        //since we want number of elements so added 1 to all results
        
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        sort(nums.begin(),nums.end());
        vector<int> prefixSum(nums.size(),0);
        
        prefixSum[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefixSum[i] += prefixSum[i-1] + nums[i];
        }
        
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++)
        {
            int q = queries[i];
            
            ans[i] = lowerbound(prefixSum,q);
        }
        
        return ans;
    }
};