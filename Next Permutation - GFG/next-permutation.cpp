//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int idx = -1;
        for(int i = arr.size()-2;i>=0;i--)
        {
            if(arr[i] < arr[i+1])
            {
                idx= i;
                break;
            }
        }
        
        if(idx == -1)
        {
            
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        int idx2 = -1;
        int minimum = INT_MAX;
        for(int i=idx+1;i<N;i++)
        {
            if(arr[i] > arr[idx] && arr[i] <= minimum)
            {
                minimum = arr[i];
                idx2 = i;
            }
        
        }
        swap(arr[idx],arr[idx2]);
        
        sort(arr.begin()+idx+1,arr.end());
        
        return arr;
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends