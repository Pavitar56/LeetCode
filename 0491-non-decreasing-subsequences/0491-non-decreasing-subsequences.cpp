class Solution {
public:
    
    vector<vector<int>> ans;
    set<vector<int>> unique;
    void solve(int ind,vector<int> &nums,vector<int> &curr)
    {
        if(ind == nums.size())
        {
            if(curr.size() >= 2 )
            {
                unique.insert(curr);
            }
            
            return;
            
        }
        
        
        //not take
        solve(ind + 1,nums,curr);
        
        //take    
        if(curr.size() == 0 || nums[ind] >= curr.back())
        {
            curr.push_back(nums[ind]);
            solve(ind+1,nums,curr);
            curr.pop_back();
        }
    
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> curr;
        solve(0,nums,curr);
        
        for(auto it=unique.begin();it != unique.end();it++)
        {
            ans.push_back(*it);
        }
        
        return ans;
        
    }
};