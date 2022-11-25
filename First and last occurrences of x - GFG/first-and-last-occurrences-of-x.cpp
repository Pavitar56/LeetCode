//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int lower_bound(int arr[],int n,int target)
{
    int start = 0;
    int end = n - 1;
    
    while(start<end)
    {
        int mid = start + (end-start)/2;
        
        if(target <= arr[mid])
        {
            end= mid;
        }
        else
        {
            start = mid+1;
        }
    }
    
    if(arr[end] != target)
    {
        return -1;
    }
    
    return end;
}

int upper_bound(int arr[],int n,int target)
{
    int start = 0;
    int end = n - 1;
    
    while(start<end)
    {
        int mid = start + (end-start)/2;
        
        if(target >= arr[mid])
        {
            start = mid +1;
        }
        else
        {
            end = mid;
        }
    }
    
    if(arr[end] == target)
    {
        return end;
    }
    if(arr[end-1] == target)
    {
        return end-1;
    }
    
    return -1;
}


vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans = {lower_bound(arr,n,x) , upper_bound(arr,n,x)};
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends