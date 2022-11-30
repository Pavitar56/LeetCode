//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    unordered_map<int,string> mp = {
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
    };
    
    vector<string> helper(int a[],int n,int idx)
    {
        if(idx == n-1)
        {
            vector<string> ans;
            string num = mp[a[idx]];
            
            for(int i=0;i<num.size();i++)
            {
                string t="";
                ans.push_back(t + num[i]);
            }
            
            return ans;
        }
        
        
        vector<string> smallOutput = helper(a,n,idx+1);
        
        string num = mp[a[idx]];
        
        vector<string> output;
        
        for(int i=0;i<smallOutput.size();i++)
        {
            for(int j=0;j<num.size();j++)
            {
                output.push_back(num[j] + smallOutput[i]);
            }
            
        }
        
        return output;
        
    }
    
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans =  helper(a,N,0);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends