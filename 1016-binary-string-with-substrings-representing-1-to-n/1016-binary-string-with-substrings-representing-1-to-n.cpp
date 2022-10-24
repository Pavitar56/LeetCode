class Solution {
public:
    
        
        
    string toBinary(int i)
    {
        string r;
        while (i != 0)
        {
            r = (i%2 == 0 ? '0':'1') + r;
            i /= 2;
        }
        return r;
    }
        
    bool queryString(string s, int n) 
    {
        for (int i = 1; i <= n; i++)
        {
            if(s.find(toBinary(i)) ==  string::npos) 
                return false;
        }
        
       
        return true; 
  
    }
};