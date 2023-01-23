class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        unordered_map<int,int> freq1;
        unordered_map<int,int> freq2;
        
        for(int i=0;i<trust.size();i++)
        {
          
           freq1[trust[i][0]]++;
           freq2[trust[i][1]]++;
        }
        
        int maxfreq =INT_MIN;
        int maxkey=0;
    
        for(auto it = freq2.begin();it != freq2.end();it++)
        {
           
            if(it->second > maxfreq)
            {
                maxfreq = it->second;
                maxkey = it->first;
            }
            
            
        }
        //cout<<maxkey<<" "<<maxfreq;
        if(maxfreq == (n-1) && freq1.count(maxkey) == 0)
        {
            return maxkey;
            
        }
        
        return -1;
        
    }
};