class Solution {
public:
    /*
    int solve(vector<int> &nums,int ind,int p,vector<vector<int>> &dp)
    {
        if(p == 0)
        {
            return 0;
        }
        if(ind >= nums.size())
        {
            return INT_MAX;
        }
        
        if(dp[ind][p] != -1)
        {
            return dp[ind][p];
        }
        
        int not_take = solve(nums,ind+1,p,dp);
        
        int take = INT_MAX;
        
        if(ind < (nums.size()-1))
            take = max(abs(nums[ind] - nums[ind+1]),solve(nums,ind+2,p-1,dp));
        
        return dp[ind][p] = min(take,not_take);
        
        
        
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> dp(nums.size(),vector<int>(p+1,-1));
        return solve(nums,0,p,dp);
    }
    */ int check(vector<int>&nums,int m,int p)
    {
        int i=0;
        while(i<nums.size()-1)
        {
            if(abs(nums[i]-nums[i+1])<=m)
            {
                p--;
                i=i+2;
            }
            else
            i++;
            
        }
        return p<=0?1:0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums[nums.size()-1];
        int ans=-1;

        while(i<=j)
        {
            int m=(i+j)>>1;
            if(check(nums,m,p))
            {
                ans=m;
                j=m-1;
            }
            else
            {
                i=m+1;
            }
        }
        return ans;
    }
    
};