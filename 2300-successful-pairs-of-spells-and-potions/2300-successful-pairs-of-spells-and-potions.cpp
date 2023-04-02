class Solution {
public:
    
    
    int lower_bound(vector<int> &potions,long long target)
    {
        
        int start = 0;
        int end = potions.size();
        
        int ans = -1;
        
        while(start < end)
        {
            int mid = start + (end-start)/2;
            
            if(target <= potions[mid])
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
            
        }
        
        if(start == potions.size())
        {
            return -1;
        }
        
        return start;
        
    }
    
    
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        
        sort(potions.begin(),potions.end());
        vector<int> ans(spells.size(),0);
        long long req;
        
        for(int i=0;i<spells.size();i++)
        {
            
            if(success%spells[i] == 0)
            {
                req = success/spells[i];
            }
            else
            {
                req = success/spells[i] + 1;
            }
            
            
            int idx = lower_bound(potions,req);
            
            if(idx != -1)
            {
                ans[i] = potions.size() - idx;
            }
            
            
        }
        
        return ans;
    }
};