class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
//         sort(nums.begin(),nums.end());
        
//         int start = 0;
//         int end = nums.size()-1;
//         int count=0;
        
//         while(start < end)
//         {
//             int sum = nums[start] + nums[end];
            
//             if(sum == k)
//             {
//                 count++;
//                 start++;
//                 end--;
//             }
//             else if(sum < k)
//             {
//                 start++;
//             }
//             else
//             {
//                 end--;
//             }
            
//         }
        
//         return count;
        
        unordered_map<int,int> freq;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            int target = k- nums[i];
            
            if(freq.count(target)>0)
            {
                count++;
                freq[target]--;
                if(freq[target] == 0)
                {
                    freq.erase(target);
                }
            }
            else
            {
                freq[nums[i]]++;
            }
            
            
        }
        return count;
        
    }
};