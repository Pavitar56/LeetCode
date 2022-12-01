class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int left = 0;
        int right = 0;
        unordered_map<char,bool> map ={
            {'a',true},
            {'e',true},
            {'i',true},
            {'o',true},
            {'u',true},
            {'A',true},
            {'E',true},
            {'I',true},
            {'O',true},
            {'U',true}
        };
        
        for(int i=0;i<s.size()/2;i++)
        {
            if(map.count(s[i]) > 0)
            {
                left++;
            }
        }
        
        
        
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(map.count(s[i]) > 0)
            {
                right++;
             
            }
           
            
        }
        
        return left == right;
        
        
        
        
    }
};