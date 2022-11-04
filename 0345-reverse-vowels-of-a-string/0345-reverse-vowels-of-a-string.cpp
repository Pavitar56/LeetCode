class Solution {
public:
    string reverseVowels(string s) 
    {

        string vowels="aeiouAEIOU";
        int start = 0;
        int end = s.size()-1;
        
        while(start<end)
        {
            while(start < end && vowels.find(s[start]) == string::npos)
            {
                start++;
            }
            
            
            while(start < end && vowels.find(s[end]) == string::npos)
            {
                end--;
            }
            
            
            char t = s[start];
            s[start] = s[end];
            s[end] = t;
            start++;
            end--;
            
        }
        
        return s;


        
    }
};