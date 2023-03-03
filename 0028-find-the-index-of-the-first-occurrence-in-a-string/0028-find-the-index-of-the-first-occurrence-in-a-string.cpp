class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack.size() < needle.size())
        {
            return -1;
        }
        int length = needle.size();
        
        
        for(int i=0;i<(haystack.size()-length + 1);i++)
        {
            
            if(haystack.substr(i,length) == needle)
            {
                return i;
            }
            
        }
        return -1;
    }
};