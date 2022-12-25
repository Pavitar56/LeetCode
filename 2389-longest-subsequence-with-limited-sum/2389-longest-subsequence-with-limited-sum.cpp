class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        sort(nums.begin(),nums.end());
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            
            int q = queries[i];
            
            int start = 0;
            int count = 0;
            int sum = 0;
            
            while(start < nums.size() && (sum + nums[start]) <= q)
            {
                sum += nums[start];
                start++;
                count++;
            }
            
            ans.push_back(count);
            
        }
        
        return ans;
        
        
    }
};