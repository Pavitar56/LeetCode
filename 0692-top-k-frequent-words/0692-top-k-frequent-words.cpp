class Solution {
public:
    
//     bool lex_compare(string &s1, string s2)
//     {
//         int i=0;
//         int j=0;
//         while(i<s1.size() && j<s2.size())
//         {
//             if(s1[i] > s2[j])
//             {
//                 return true;
//             }
//             i++;
//             j++;
//         }
        
//         if(i<s1.size())
//         {
//             return true;
//         }
        
//         return false;
//     }
    
    bool static cmp(const pair<string,int> &p1,const pair<string,int> &p2)
    {
        if(p1.second == p2.second)
        {
            return p1.first<p2.first;
        }
        
        return p1.second>p2.second;
    }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        
        unordered_map<string,int> freq;
        
        for(int i=0;i<words.size();i++)
        {
            freq[words[i]]++;
        }
        
        vector<pair<string,int>> allFreq;
        
        for(auto it= freq.begin();it!=freq.end();it++)
        {
            allFreq.push_back({it->first,it->second});
        }
        
        sort(allFreq.begin(),allFreq.end(),cmp);
        
        vector<string> ans;
        
        for(int i=0;i<k && i<allFreq.size();i++)
        {
            ans.push_back(allFreq[i].first);
        }
        
        return ans;
  
//         priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        
//         int count=0;
        
//         for(auto it = freq.begin(); it != freq.end() ; it++)
//         {
//             cout<<it->first<<endl;
//             if(count<k)
//             {
//                 pq.push({it->second,it->first});
//                 count++;
//                 continue;
//             }
            
//             pair<int,string> p1 = pq.top();
            
//             if(p1.first < it->second)
//             {
//                 pq.pop();
//                 pq.push({it->second,it->first});
//             }
//             else if(p1.first == it->second)
//             {
//                 cout<<p1.second<<" "<<it->first<<endl;
//                 if(lex_compare(p1.second,it->first))   //return true if p1.second > it->first lexographically
//                 {
                    
//                     pq.pop();
//                     pq.push({it->second,it->first});
//                 }
                
//             }
                
//         }
        
//         vector<string> most_k_Freq;
        
//         while(!pq.empty())
//         {
            
//             most_k_Freq.push_back(pq.top().second);
//             pq.pop();
//         }
      
//         return most_k_Freq;
    }
};