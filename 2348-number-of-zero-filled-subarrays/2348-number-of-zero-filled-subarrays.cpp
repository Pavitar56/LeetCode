class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int start = -1;
        int end = 0;
        long long ans = 0;
        unordered_map<long long int,int> mp;  //size ,number of subarrays of that size
        while(end < nums.size())
        {
            
            if(nums[end] == 0)
            {
                if(start == -1)
                {
                    start = end;
                }
                
            }
            else
            {
                if(start != -1)
                {
                    mp[end - start]++;
                    start = -1;
                }
            }
            end++;
     
        }
        
        if(start != -1)
        {
            mp[end - start]++;
        }
        
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans += it->second * (((it->first) * (it->first + 1))/2);
        }
        
        return ans;
    }
};