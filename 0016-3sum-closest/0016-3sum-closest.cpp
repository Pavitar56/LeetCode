class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        
        sort(nums.begin(),nums.end());
        
        int finaldiff= INT_MAX;
        int finalans;
        for(int i=0;i<nums.size();i++)
        {
            int find = target - nums[i];
            
            
            int start = 0;
            int end = nums.size() - 1;
            
            int diff = INT_MAX;
            int closest;
            
            while(start<end)
            {
                if(start == i)
                {
                    start++;
                    continue;
                }
                if(end == i)
                {
                    end--;
                    continue;
                }
                
                
                int sum2 =nums[start] + nums[end];
                
                if(sum2 == find)
                {
                    diff=0;
                    closest = find;
                    break;
                }
                else if(sum2<find)
                {
                    start++;
                }
                else
                {
                    end--;
                }
                
                if(abs(sum2-find)<diff)
                {
                    diff = abs(sum2-find);
                    closest = sum2;
                }
                
                
            }
            
            int sum3 = closest + nums[i];
            
            if(abs(sum3 - target) < finaldiff)
            {
                finaldiff = abs(sum3-target);
                finalans = sum3;
            }
     
        }
        
        
        return finalans;
        
    }
};