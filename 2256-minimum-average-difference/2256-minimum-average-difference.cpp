class Solution {
public:
    int minimumAverageDifference(vector<int>& nums)
    {
        
        vector<int> leftAvg(nums.size(),0);
        
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            
            leftAvg[i] = sum/(i+1);
            
        }
        
        vector<int> rightAvg(nums.size(),0);
        
        sum=0;
        int k=1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            sum += nums[i+1];
            
            rightAvg[i] = sum/k;
            k++;
        }
        
        int minimum = INT_MAX;
        int index = 0;
        for(int i=0;i<nums.size();i++)
        {
            
            if(abs(leftAvg[i] - rightAvg[i])  < minimum)
            {
                minimum = abs(leftAvg[i] - rightAvg[i]);
                index = i;
            }
        }
        
        return index;
        
    }
};