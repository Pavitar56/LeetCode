class Solution {
public:
    
    bool static compare(pair<int,int>& p1,pair<int,int>& p2)
    {
        
        return p1.first<p2.first;
        
    }
    
    
    int binary_search(vector<pair<int,int>>& maxTill,int target)
    {
        int start=0;
        int end=maxTill.size()-1;
        
        while(start<end)
        {
            
            int mid = start + (end-start)/2;
            
            if( target >= maxTill[mid].first)
            {
                start = mid +1;
            }
            else
            {
                end=mid;
            }
            
            
        }
       
        if(target >= maxTill[end].first )
        {
            return maxTill[end].second;
        }
        
        
        end--;
        if(end >=0)
        {
            return maxTill[end].second;
        }
        
        
        
        return 0;
     
        
    }
    
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<difficulty.size();i++)
        {
            v.push_back({difficulty[i],profit[i]});
        }
        
        
        sort(v.begin(),v.end(),compare);
        
        
        vector<pair<int,int>> maxTill(v.size(),pair<int,int>(INT_MIN,INT_MIN));
        
        maxTill[0].first=v[0].first;
        maxTill[0].second=v[0].second;
        int maximum = v[0].second;
        
        for(int i=1;i<v.size();i++)
        {
            maxTill[i].first = v[i].first;
            maximum = max(v[i].second,maximum);
            maxTill[i].second = maximum;
        }
        
        int ans=0;
        
        for(int i=0;i<worker.size();i++)
        {
            
            int p = binary_search(maxTill,worker[i]);
            ans +=p;
            
        }
        
        
        return ans;
        
    }
};