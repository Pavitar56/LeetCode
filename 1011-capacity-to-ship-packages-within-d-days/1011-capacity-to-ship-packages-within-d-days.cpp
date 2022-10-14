class Solution {
public:
    
    bool possible(int capacity,vector<int>& weights, int days)
    {
        
        int sum = 0;
        int totaldays=0;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>capacity)
            {
                return false;
            }
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
        
        int start = 1;
        int end = INT_MAX;
        
        
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