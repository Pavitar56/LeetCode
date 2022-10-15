class Solution {
public:
    int numSplits(string s) 
    {
//         vector<int> prefix(s.size());
//         set<char> prehelper;
        
//         for(int i=0;i<s.size();i++)
//         {
//             prehelper.insert(s[i]);    
//             prefix[i] = prehelper.size();
        
//         }
        
//         vector<int> suffix(s.size());
//         set<char> suffhelper;
        
//         for(int i=s.size()-1;i>=0;i--)
//         {
//             suffhelper.insert(s[i]);
//             suffix[i] = suffhelper.size();
//         }
        
        
//         int count = 0;
//         for(int i=0;i<s.size()-1;i++)
//         {
//             if(prefix[i] == suffix[i+1])
//             {
//                 count++;
//             }
//         }
        
        
        
//         return count;
        
        unordered_map<char,int> preMap,sufMap;
        
        for(int i=0;i<s.size();i++)
        {
            sufMap[s[i]]++;
        }
        
        int count=0;
        
        for(int i=0;i<s.size();i++)
        {
            preMap[s[i]]++;
            
            sufMap[s[i]]--;
            
            if(sufMap[s[i]] == 0)
            {
                sufMap.erase(s[i]);
            }
            
            if(preMap.size() == sufMap.size() && preMap.size() != 0)
            {
                count++;
            }
            
            
        }
        
        return count;
    }
};