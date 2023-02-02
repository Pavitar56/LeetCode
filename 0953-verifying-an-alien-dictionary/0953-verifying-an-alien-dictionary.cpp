string global_order;
    bool compare(string &s1,string &s2)
    {
        int i=0;
        int j=0;
        
        while(i < s1.size() && j < s2.size())
        {
            int temp1 = global_order.find(s1[i]);
            int temp2 = global_order.find(s2[j]);
            
            if( temp1 < temp2)
            {
                return true;
            }
            else if(temp2 < temp1)
            {
                return false;
            }
            i++;
            j++;
        }
        
        if(i == s1.size())
        {
            return true;
        }
        
        return false;
    }
    

class Solution {
public:
   
   
    
    bool isAlienSorted(vector<string>& words, string order) {
        
        
        vector<string> sorted = words;
        global_order = order;
        
        sort(sorted.begin(),sorted.end(),compare);
        
        if(sorted == words)
        {
            return true;
        }
        
        return false;
        
        
    }
};