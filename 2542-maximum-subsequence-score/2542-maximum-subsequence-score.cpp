class Solution {
public:
    
    long long int solve(vector<int>& nums1, vector<int>& nums2,int ind, int k,long long int sum,int minimum,vector<vector<long long int>> &dp)
    {
        if(k==0)
        {
            if(sum == 0 || minimum == INT_MAX)
            {
                return INT_MIN;
            }
            return sum * minimum;
        }
        
        if(ind == nums1.size())
        {
            return INT_MIN;
        }
        
        if(dp[ind][k] != -1)
        {
            cout<<ind<<" "<<k<<" "<<dp[ind][k]<<endl;
            return dp[ind][k];
        }
        
        
        long long int take = solve(nums1,nums2,ind+1,k-1,sum + nums1[ind],min(minimum,nums2[ind]),dp);
        long long int notTake = solve(nums1,nums2,ind+1,k,sum,minimum,dp);
        
        
        
        return dp[ind][k] = max(take,notTake);
        
        
        
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        //  vector<vector<long long int>> dp(nums1.size(),vector<long long int>(k+1,-1));
        // return solve(nums1,nums2,0,k,0,INT_MAX,dp);
        
        long long n = nums1.size(), s = 0, ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) v.push_back({nums2[i], nums1[i]});
        sort(v.begin(), v.end());
        
        for(int i=n-1; i>=0; i--) {
            pq.push(v[i].second);
            s += v[i].second;
            if(pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) ans = max(ans, v[i].first * s);
        }
        return ans;
        
        
    }
};