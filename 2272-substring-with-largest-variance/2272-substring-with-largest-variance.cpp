/*
class Solution {
public:
    
    int solve(string &s,int ind,unordered_map<char,int> &mp)
    {
        if(ind == s.size())
        {
            int maximum = INT_MIN;
            int minimum = INT_MAX;
            
            int ans = 0;
            
            for(auto it = mp.begin();it != mp.end(); it++)
            {
                maximum = max(maximum,it->second);
                minimum = min(minimum,it->second);
                
                if(maximum !=0 && minimum != 0)
                {
                    ans = max(ans,maximum - minimum);
                }
            }
            
            return ans;
        }
        
        
        mp[s[ind]]++;
        
        int take = solve(s,ind+1,mp);
        
        mp[s[ind]]--;
        
        int notTake = solve(s,ind+1,mp);
        
        return dp[ind] = max(take,notTake);
    }
    
    
    
    int largestVariance(string s) {
          
        unordered_map<char,int> mp;
        return solve(s,0,mp);
        
    }
    
    
};
*/
class Solution {
public:
    
    int a_minus_b(char a, char b, string& s) {
     //   cout<<a<<","<<b<<endl;
        int best_sum = 0;
        int a_count = 0, b_count = 0;
        for (char c : s) {
            if (c == a) a_count++;
            else if (c == b) b_count++;
            else continue;
            if (b_count > 0)
                best_sum = max(best_sum, a_count-b_count);
            else if ( b_count==0 ) //handle "bbaaaa" for previous b
                best_sum = max(best_sum, a_count-1);
            if (a_count < b_count ) {
                a_count = b_count = 0;
            }
        }
    //    cout<<best_sum<<endl;
        return best_sum;
    }

    int largestVariance(string s) {
        unordered_map<char, int> freq;
        for (char c : s){
            if (freq.count(c)==0) freq[c]=1;
            else freq[c]++;
        }
         
        int ans = 0;
        for (auto [a, fa]: freq) {
            for (auto [b, fb]: freq) {
                if (a!=b)
                    ans = max(ans, a_minus_b(a, b, s));
            }
        }
        return ans;
    }
};