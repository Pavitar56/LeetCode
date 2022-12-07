//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n)
{
    //code
    
    unordered_map<int,bool> mp;
    
    for(int i=0;i<size;i++)
    {
        int target = n + arr[i];
        int target2 = arr[i] - n;
        if(mp.count(target) > 0 || mp.count(target2) >0)
        {
            return true;
        }
        
        mp[arr[i]] = true;
    }
    
    return false;
    
    
}