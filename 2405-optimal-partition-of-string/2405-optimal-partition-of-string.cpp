class Solution {
public:
    int partitionString(string s) {
        
        vector<int> freq(26,0);
        int ans = 1;
        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i] - 'a'] > 0)
            {
                ans++;
                fill(freq.begin(),freq.end(),0);
                
            }
            
            freq[s[i]-'a']++;
            
            
            
        }
        
        return ans;
        
        
        
    }
};