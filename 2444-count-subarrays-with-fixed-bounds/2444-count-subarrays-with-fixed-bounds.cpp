class Solution {
public:
    long long countSubarrays(vector<int>& num, int minK, int maxK) {
        
        
        long ans = 0;
        bool minFound = false, maxFound = false;
        int start = 0, minStart = 0, maxStart = 0;
        
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] < minK || num[i] > maxK) 
            {
                minFound = false;
                maxFound = false;
                start = i+1; 
            }
 
            if (num[i] == minK) 
            {
                minFound = true;
                minStart = i;
            }
    
            if (num[i]== maxK) 
            {
                maxFound = true;
                maxStart = i;
            }
       
            if (minFound && maxFound) 
            {
                ans += (min(minStart, maxStart) - start + 1);
            }
        }
        return ans;

        
    }
};