class Solution {
public:
    
    
    
    bool check(vector<int> &v1,vector<int> &v2)
    {
        
        for(int i=0;i<26;i++)
        {
            if(v1[i] > 0 && v2[i] > 0)
            {
                return false;
            }
            
            
        }
        
        return true;
    }
    
    
    void fillAllFreq(vector<vector<int>> &AllFreq,vector<string> &words)
    {
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                AllFreq[i][words[i][j] - 'a']++;
            }
            
        }
        
        
    }
    
    int maxProduct(vector<string>& words)
    {
        
        vector<vector<int>> AllFreq(words.size(),vector<int>(26,0));
        
        fillAllFreq(AllFreq,words);
        
        int maxProductAns = 0;
        for(int i=0;i<words.size();i++)
        {
            vector<int> v1(26,0);
          
            
            for(int j=i+1;j<words.size();j++)
            {
                vector<int> v2(26,0);
             
                
                if(check(AllFreq[i],AllFreq[j]))
                {
                    int temp = (words[i].size() * words[j].size());
                    maxProductAns = max(maxProductAns,temp);
                }
                
                
            }
            
        }
        
        return maxProductAns;
        
        
    }
};