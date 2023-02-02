// string global_order;
//     bool compare(string &s1,string &s2)
//     {
//         int i=0;
//         int j=0;
        
//         while(i < s1.size() && j < s2.size())
//         {
//             int temp1 = global_order.find(s1[i]);
//             int temp2 = global_order.find(s2[j]);
            
//             if( temp1 < temp2)
//             {
//                 return true;
//             }
//             else if(temp2 < temp1)
//             {
//                 return false;
//             }
//             i++;
//             j++;
//         }
        
//         if(i == s1.size())
//         {
//             return true;
//         }
        
//         return false;
//     }
    

// class Solution {
// public:
   
   
    
//     bool isAlienSorted(vector<string>& words, string order) {
        
        
//         vector<string> sorted = words;
//         global_order = order;
        
//         sort(sorted.begin(),sorted.end(),compare);
        
//         if(sorted == words)
//         {
//             return true;
//         }
        
//         return false;
        
        
//     }
// };

class Solution {
public:
    unordered_map<char,int> orderMap;
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.length(); i++){
            orderMap[order[i]] = i;
        }
    
        for(int i =1;i< words.size();i++){
            if(!compare(words[i],words[i-1]))return false;
        }
        return true;
    }
    
    bool compare(string s1, string s2){
            int j = 0;
        while(j<s1.length() && j<s2.length()){
            if(s1[j] == s2[j]) j++;
            else if(orderMap[s1[j]]>orderMap[s2[j]]) return true;
            else return false;
        }
        if(s1.length()<s2.length())return false;
        return true;
    }
};