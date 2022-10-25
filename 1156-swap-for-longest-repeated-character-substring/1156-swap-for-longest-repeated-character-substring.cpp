class Solution {
public:
    //tc= O(26 * N)
    int maxRepOpt1(string text) 
    {
        
        vector<int> freq(26,0);
        
        for(int i=0;i<text.size();i++)
        {
            
            freq[text[i] - 'a']++;
            
        }
        
        
       int result  = 0;
        
        for(char c = 'a' ; c<='z' ; c++)
        {
            
            if(freq[c - 'a'] == 0)
            {
                continue;
            }
            
            
            int mismatch_count = 0;
            int lc= 0;
            int rc = 0;
            
            
            for(int i=0;i<text.size();i++)
            {
                
                if(text[i] == c && mismatch_count == 0)
                {
                    lc++;
                }
                else if(text[i] == c && mismatch_count == 1)
                {
                    rc++;
                }
                else if(text[i] != c)
                {
                    mismatch_count++;
                }
                
                
                if(freq[c - 'a'] > (lc+rc))
                {
                    result = max(result,lc+rc+1);
                }
                else
                {
                    result = max(result,lc+rc);
                }
                
                
                if(mismatch_count > 1)
                {
                    lc=rc;
                    rc=0;
                    mismatch_count = 1;
                }
                
                
            }
            
            
        }
        
        
        return result;
    }
};