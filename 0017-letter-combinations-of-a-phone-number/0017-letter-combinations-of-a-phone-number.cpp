class Solution {
public:
    vector<string> ans;
    unordered_map<char,string> mp = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    
    void solve(string &digits,int ind,string &curr)
    {
        if(ind == digits.size())
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i=0; i < mp[digits[ind]].size() ;i++)
        {
            curr.push_back(mp[digits[ind]][i]);
            solve(digits,ind+1,curr);
            curr.pop_back();
        }
        
        return;
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        if(digits == "")
        {
            return ans;
        }
        
        string curr = "";
        solve(digits,0,curr);
        
        return ans;
    }
};