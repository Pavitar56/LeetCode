class Solution {
public:
    
    
    int subarraySum(vector<int>& nums, int k)
    {
//         int count=0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             int sum=0;
            
//             for(int j = i;j<nums.size();j++)
//             {
//                 sum += nums[j];
                
//                 if(sum == k)
//                 {
//                     count++;
//                 }
                
//             }
            
//         }
        
//         return count;
        
        
        
//         vector<int> subSum(nums.size(),0);
//         int sum=0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];
//             subSum[i]=sum;
//         }
        
//         unordered_map<int,int> map;
//         int ans=0;
//         for(int i=0;i<subSum.size();i++)
//         {
//             if(subSum[i] == k)
//             {
//                 ans++;
//             }
            
//             if(map.count(subSum[i] - k)>0)
//             {
//                 ans += map[subSum[i] - k];
//             }
//             map[subSum[i]]++;
            
            
            
//         }
        
//         return ans;
        
        
        int sum=0;
        int ans=0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
            if(sum == k)
            {
                ans++;
            }
            
            ans += map[sum - k];
            
            map[sum]++;
        }
        return ans;
    }
};