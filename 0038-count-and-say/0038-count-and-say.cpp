class Solution {
public:
    string countAndSay(int n) 
    {
        
//         if(n==1)
//         {
//             return "1";
//         }
        
//         string temp = countAndSay(n-1);
        
//         string ans="";
        
//         int len=temp.size();
//         int si=0;
//         int ei=0;
        
//         char t = temp[si];
        
//         while(ei<len)
//         {
//             while(ei<len && temp[si] == temp[ei])
//             {
//                 ei++;
//             }
            
            
//             int count = ei- si;
            
//             ans += to_string(count) + temp[si];
//             si=ei;
            
//         }
        
//         return ans;
        
        
        if(n==1)
        {
            return "1";
        }
        
        string prev = "1";
        
        for(int i=2;i<=n;i++)
        {
            int si=0;
            int ei=0;
            int len =prev.size();
            string next = "";
            while(ei<len)
            {
                while(ei<len && prev[si] == prev[ei])
                {
                    ei++;
                }


                int count = ei- si;

                next += to_string(count) + prev[si];
                si=ei;

            }
            
            prev=next;
        }
        return prev;
    }
};