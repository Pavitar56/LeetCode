class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int> winFreq;
        unordered_map<int,int> lossFreq;
        
        vector<vector<int>> ans(2,vector<int>(0));
        
        for(int i=0;i<matches.size();i++)
        {
            winFreq[matches[i][0]]++;
            lossFreq[matches[i][1]]++;
        }
        
        
        
        for(auto it = winFreq.begin();it != winFreq.end();it++)
        {
            if(lossFreq.count(it->first) <=0)
            {
                ans[0].push_back(it->first);
            }
        }
        
        for(auto it = lossFreq.begin();it != lossFreq.end();it++)
        {
            if(lossFreq[it->first] == 1)
            {
                ans[1].push_back(it->first);
            }
        }
        
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};