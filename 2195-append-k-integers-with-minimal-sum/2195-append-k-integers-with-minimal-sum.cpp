class Solution {
public:
    
    
    
    long long minimalKSum(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        
        long long int temp =k;
        
        long long int sum = temp*(temp+1)/2;
   
        unordered_map<int,bool> map;
        for(int i=0;i<nums.size();i++)
        {
            
            if(nums[i]<=k && map.count(nums[i])<=0)
            {
                k++;
                sum = sum - nums[i] + k;
            
            }
            else if(nums[i]>k)
            {
                break;
            }
            map[nums[i]] = true;
        }
        
        return sum;
    }
};