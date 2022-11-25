//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        
        string minWord = arr[0];
        
        for(int i=1;i<N;i++)
        {
            if(arr[1].size() < minWord.size())
            {
                minWord = arr[i];
            }
            
        }
        
        for(int i = minWord.size() ; i > 0;i--)
        {
            
            string prefix = minWord.substr(0,i);
            bool flag = true;
            
            for(int j = 0; j<N;j++)
            {
                string word = arr[j];
                
                if(prefix != word.substr(0,i))
                {
                    flag = false;
                    break;
                }
                
                
            }
            
            if(flag == true)
            {
                return prefix;
            }
            
        }
        
        return "-1";
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends