class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        for(int i = 0;i < capacity.size();i++)
        {
            capacity[i] = capacity[i]  - rocks[i];
            
        }
        
        sort(capacity.begin(),capacity.end());
        
        int count = 0;
        int i=0;
        
        while(i < capacity.size() && capacity[i] <= additionalRocks)
        {
            count++;
            
            additionalRocks -= capacity[i];
            i++;
            
        }
        return count;
        
    }
};