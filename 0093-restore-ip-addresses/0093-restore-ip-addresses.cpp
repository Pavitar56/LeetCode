class Solution {
public:
    vector<string> ans;
    
    
    void solve(string &s,int ind,string &curr,int dots)
    {
        if(ind == s.size())
        {
            if(dots == 4)
            {
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }
        
        string orginial = curr;
        
        string temp = s.substr(ind,1);
        curr = orginial + temp + ".";
        solve(s,ind+1,curr,dots+1);
        
        if((ind +1) < s.size())
        {
            temp = s.substr(ind,2);
            if(temp[0] != '0')
            {
                curr = orginial + temp + ".";
                solve(s,ind+2,curr,dots + 1);
            }
        }
        
        if((ind + 2) < s.size())
        {
            temp = s.substr(ind,3);
            if(temp[0] != '0' && stoi(temp) <=255)
            {
                curr= orginial + temp + ".";
                solve(s,ind+3,curr,dots+1);
            }
        }
        return;
               
    }
    
    vector<string> restoreIpAddresses(string s) {
        string curr="";
        solve(s,0,curr,0);
        return ans;
    }
};