class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        
        s.push_back(' ');
        
        vector<string> words;
        
        int start = 0;
        int end = 0;
        
        while(end < s.size())
        {
            while(s[end] != ' ')
            {
                end++;
            }
            
            
            words.push_back(s.substr(start,end-start));
  
            start=end +1;
            end++;
                  
        }
        
        
        unordered_map<string,char> mp1;
        char ch = 'a';
        string hash ="";
        
        for(int i=0;i<words.size();i++)
        {
            if(mp1.count(words[i]) > 0)
            {
                hash += mp1[words[i]];
            }
            else
            {
                
                mp1[words[i]] = ch;
                hash += mp1[words[i]];
                ch++;
            }
        }
        
        unordered_map<char,char> mp2;
        ch = 'a';
        string hash2 ="";
        
        for(int i=0;i<pattern.size();i++)
        {
            if(mp2.count(pattern[i]) > 0)
            {
                hash2 += mp2[pattern[i]];
            }
            else
            {
                
                mp2[pattern[i]] = ch;
                hash2 += mp2[pattern[i]];
                ch++;
            }
        }
        
        
        
        
        return hash == hash2;
    }
};