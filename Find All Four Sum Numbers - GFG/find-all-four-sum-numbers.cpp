//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        
        
        vector<vector<int>> ans;
        
        
        sort(arr.begin(),arr.end());
        
        
        
        for(int i=0;i<arr.size();i++)
        {
            
            if(i > 0 && arr[i] == arr[i-1])
            {
                continue;
            }
            
            for(int j = i+1;j<arr.size();j++)
            {
                
                if(j> (i+1) && arr[j] == arr[j-1])
                {
                    continue;
                }
                
                
                int target = k - arr[i] - arr[j];
                
                
                int start = j+1;
                int end = arr.size()-1;
                
                //cout<<start<<" "<<end<<endl;
                while(start < end)
                {
                    if((arr[start] + arr[end]) == target)
                    {
                        ans.push_back({arr[i],arr[j],arr[start],arr[end]});
                        
                        int prevS = arr[start];
                        int prevE = arr[end];
                        
                        while(start < end && arr[start] == prevS)
                        {
                            start++;
                        }
                        while(start < end && arr[end] == prevE)
                        {
                            end--;
                        }
                    }
                    else if((arr[start] + arr[end]) < target)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                    
                }
               
                
                
            }
            
            
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends