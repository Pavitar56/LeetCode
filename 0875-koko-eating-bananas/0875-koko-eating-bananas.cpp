class Solution {
public:
    int findMax(vector<int>& piles)
    {
        int maximum = INT_MIN;
        
        for(int i=0;i<piles.size();i++)
        {
            maximum = max(piles[i],maximum);
            
        }
        
        return maximum;
        
    }
    
    
    bool possible(vector<int> &piles,int h , int contender)
    {
        int totalHours = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%contender == 0)
            {
                totalHours += piles[i]/contender;
            }
            else
            {
                totalHours += piles[i]/contender + 1;
            }
            
            if(totalHours > h)
            {
                return false;
            }
            
        }
        
        return true;
        
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        
        int maximum = findMax(piles);
        
        int start = 1;
        int end = maximum;
        
        while(start < end)
        {
            int mid = (start + end)/2;
            
            if(possible(piles,h,mid))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
            
        }
        
        return end;
        
        
        
    }
};