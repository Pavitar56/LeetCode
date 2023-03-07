class Solution {
public:
    
    long long solve(vector<int> &time,long long int givenTime,int totaltrips)
    {
        
        long long int trips = 0;
        for(int i=0;i<time.size();i++)
        {
            
            trips += givenTime/time[i];
            if(trips > totaltrips)
            {
                return trips;
            }
        }
        
        return trips;
        
    }
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        
        
        long long int start = 0;
        long long int end = LLONG_MAX;
        long long int ans = LLONG_MAX;
        
        while(start <= end)
        {
            long long int mid = start + (end-start)/2;
            
            
            if(solve(time,mid,totalTrips) >= totalTrips)
            {
                ans = min(ans,mid);
                end = mid -1;
                
            }
            else
            {
                start = mid+1;
            }
            
            
            
        }
        
        return ans;
        
        
    }
};