class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         
        unordered_map<int, int> count; // hash map to store the frequency of the elements in the subarray
        
        int i, j; // variables i and j are used to keep track of the subarray boundaries
        
        int ans = 0;
        for (i = 0, j = 0; j < fruits.size(); ++j) 
        {
            count[fruits[j]]++; // increase the count of the current fruit
            
            if (count.size() > 2) 
            { 
                count[fruits[i]]--; // reduce the count of the first fruit 
                
                if (count[fruits[i]] == 0)
                {
                    count.erase(fruits[i]);  //remove it from the map if its count becomes 0
                }
                
                i++; // move the start of the subarray to the right
            }
            
            ans = max(ans,j-i+1);
        }
        
        return ans; // return the length of the longest subarray with at most two unique elements
    }
};