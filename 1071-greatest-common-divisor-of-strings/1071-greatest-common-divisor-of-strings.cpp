class Solution {
public:
    
    bool divisible(string &str1,string &str2,string &prefix)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        int lenp = prefix.size();
        
        if(len1%lenp == 0 && len2%lenp == 0)
        {
            int count1 = len1/lenp;
            int count2 = len2/lenp;
            
            string temp1 = "";
            string temp2 = "";
            
            for(int i=1;i<=count1;i++)
            {
                temp1 += prefix;
            }
            
            for(int i=1;i<=count2;i++)
            {
                temp2 += prefix;
            }
            
            if(temp1 == str1 && temp2 == str2)
            {
                return true;
            }
            
            
        }
        
        return false;
    }
    
    
    string gcdOfStrings(string str1, string str2) {
        
//         string small;
//         string big;
        
//         if(str1.size() < str2.size())
//         {
//             small = str1;
//             big = str2;
//         }
//         else
//         {
//             small = str2;
//             big = str1;
//         }
        
        
//         for(int len = small.size(); len >= 1 ; len--)
//         {
//             string prefix = small.substr(0,len);
            
//             if(prefix == big.substr(0,len))
//             {
//                 if(divisible(str1,str2,prefix))
//                 {
//                     return prefix;
//                 }
//             }
            
            
//         }
        
//         return "";
        
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
        
    }
};