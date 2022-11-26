//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    
	    
	    string ans = "";
	    unordered_map<char,bool> exists;
	    for(int i=0;i<str.size();i++)
	    {
	        
	        if(exists.count(str[i]) <= 0)
	        {
	            ans +=str[i];
	        }
	        
	        exists[str[i]] = true;
	        
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends