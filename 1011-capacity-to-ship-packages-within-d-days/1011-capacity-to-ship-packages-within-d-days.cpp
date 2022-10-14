class Solution {
public:
    
    bool possible(int capacity,vector<int>& weights, int days)
    {
        
        int sum = 0;
        int totaldays=0;
        for(int i=0;i<weights.size();i++)
        {
            sum += weights[i];
            
            if(sum > capacity)
            {
                sum = weights[i];
                totaldays++;
            }
      
            if(totaldays > days)
            {
                return false;
            }
            
        }
        totaldays++;
        if(totaldays > days)
        {
            return false;
        }
        
        
        //cout<<capacity<<" ";
        return true;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        //since all packages must be deleieverd so smallest capacity is max weight of package in array
        //and max capacity is sum of all weights;
        
        
        
        
        int start = INT_MIN;
        int end = 0;
        
        for(int i=0;i<weights.size();i++)
        {
            start=max(start,weights[i]);
            end += weights[i];
        }
        
        
        while(start < end)
        {
            int mid = start + (end -start) / 2;
            
            
            if(possible(mid,weights,days))
            {
                end = mid;
                
            }
            else
            {
                start = mid+1;
            }
        }
        
        
        return end;
        
    }
};