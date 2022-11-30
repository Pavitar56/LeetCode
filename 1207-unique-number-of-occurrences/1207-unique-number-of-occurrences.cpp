class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int> freq;
        for(int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        
        
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            
            for(auto it2=freq.begin();it2!=freq.end();it2++)
            {
                if(it->first != it2->first && it->second == it2->second)
                {
                    return false;
                }
                
            }
        }
        return true;
    }
};