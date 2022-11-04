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
        
        if(s.size() < p.size())
        {
            return {};
        }
        
        
        vector<int> ans;
        vector<int> pFreq(26,0);
        vector<int> windowFreq(26,0);
        
        
        int si=0;
        int ei=0;
        
        
        while(ei<s.size())
        {
            if(ei < p.size())
            {
                pFreq[p[ei]-'a']++;
                windowFreq[s[ei] - 'a']++;
                
            }
            else
            {
                bool flag = true;

                for(int k=0;k<26;k++)
                {
                    if(windowFreq[k] != pFreq[k])
                    {
                        flag=false;
                        break;
                    }
                }

                if(flag==true)
                {
                    ans.push_back(si);
                }

                windowFreq[s[si] - 'a']--;
                windowFreq[s[ei] - 'a']++;
                si++;
            }
            
            ei++;
      
        }
        
        bool flag = true;

        for(int k=0;k<26;k++)
        {
            if(windowFreq[k] != pFreq[k])
            {
                flag=false;
                break;
                
            }

           
        }
        
        if(flag==true)
        {
            ans.push_back(si);
        }
        
        
        return ans;
        
        
    }
};