class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
//         sort(p.begin(),p.end());
//         vector<int> ans;
        
//         for(int i=0;i<s.size();i++)
//         {
//             string temp = s.substr(i,p.size());
            
//             sort(temp.begin(),temp.end());
            
//             if(temp == p)
//             {
//                 ans.push_back(i);
//             }
//         }
        
        
//         return ans;
        
        vector<int> ans;
        vector<int> pFreq(26,0);
        
        for(int i=0;i<p.size();i++)
        {
            pFreq[p[i]-'a']++;
        }
        
        
        for(int i=0;i<s.size();i++)
        {
            string temp = s.substr(i,p.size());
            
            vector<int> tFreq(26,0);
            
            for(int j=0;j<temp.size();j++)
            {
                tFreq[temp[j]-'a']++;
            }
            
            bool flag = true;
            
            for(int k=0;k<26;k++)
            {
                if(tFreq[k] != pFreq[k])
                {
                    flag=false;
                    break;
                }
            }
            
            if(flag==true)
            {
                ans.push_back(i);
            }
            
        }
        
        return ans;
        
        
    }
};