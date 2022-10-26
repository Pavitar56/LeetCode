class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        
        int result = 0;
        for(char c = 'A';c<='Z';c++)
        {
            
            int si = 0;
            int ei = 0;
            int mismatch_count = 0;
          
            
            while(ei  < s.size())
            {
                if(s[ei] == c && mismatch_count <= k)
                {
                   
                    result = max(result,ei-si+1);
                   
                }
                else if(s[ei] != c  && mismatch_count < k)
                {
                    
                    result = max(result,ei-si+1);
                    mismatch_count++;
                }
                else if(s[ei] != c && mismatch_count >=k)
                {
                    mismatch_count++;
                }
                
                if(mismatch_count>k)
                {
                    if(s[si] !=c)
                    {
                        mismatch_count--;
                    }
                    si++;
                    
                }
                
                
                ei++;
                
            }
        
            
        }
        
        return result;
        
    }
};