class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> freq;
        
        for(int i=0;i<s.size();i++)
        {
            
            freq[s[i]]++;
            
        }
        vector<pair<int,char>> v;
        
        for(auto it = freq.begin();it!=freq.end();it++)
        {
            v.push_back({it->second,it->first});
        }
        sort(v.begin(),v.end());
        string ans="";
        
        for(int j = 0;j<v.size();j++)
        {
            for(int i=0;i< (v[j].first);i++)
            {
                ans += v[j].second;
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};