class Solution {
public:
 
    //for // code TC =O(N logN)  SC= O(N)
//     bool static cmp(const pair<string,int> &p1,const pair<string,int> &p2)
//     {
//         if(p1.second == p2.second)
//         {
//             return p1.first<p2.first;
//         }
        
//         return p1.second>p2.second;
//     }
    
    
//     vector<string> topKFrequent(vector<string>& words, int k) 
//     {
        
//         unordered_map<string,int> freq;
        
//         for(int i=0;i<words.size();i++)
//         {
//             freq[words[i]]++;
//         }
        
//         vector<pair<string,int>> allFreq;
        
//         for(auto it= freq.begin();it!=freq.end();it++)
//         {
//             allFreq.push_back({it->first,it->second});
//         }
        
//         sort(allFreq.begin(),allFreq.end(),cmp);
        
//         vector<string> ans;
        
//         for(int i=0;i<k && i<allFreq.size();i++)
//         {
//             ans.push_back(allFreq[i].first);
//         }
        
//         return ans;
    
    class cmp
    {
        public:
        bool operator()(pair<int,string> a, pair<int,string> b) const
        {
            if(a.first < b.first) 
                return true;
            else if(a.first == b.first && a.second>b.second) 
                return true;

            return false;
        }
    };



    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> ump;
        
        for(auto &w : words) 
            ump[w]++;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        
        for(auto &m : ump)
            pq.push({m.second,m.first});
        
        vector<string> vec;
        while(k--)
        {
            vec.push_back(pq.top().second);
            pq.pop();
        }
        return vec;
    }
    

};