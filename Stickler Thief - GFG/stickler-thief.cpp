//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int maximum(int arr[],int idx,vector<int> &dp)
    {
        
        if(idx == 0)
        {
            return arr[idx];
        }
        
        if(idx < 0)
        {
            return 0;
        }
        
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        
        int notTake = maximum(arr,idx-1,dp);
        int take = arr[idx] + maximum(arr,idx-2,dp);
        
        
        return dp[idx]=max(take,notTake);
        
    }
    
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // vector<int> dp(n,-1);
        // return maximum(arr,n-1,dp);
        
        // vector<int> dp(n,0);
        // dp[0] = arr[0];
        
        int prev,prev2;
        
        prev = arr[0];
        prev2=0;
        
        for(int idx=1;idx<n;idx++)
        {
            
            int notTake = prev;
            int take = arr[idx] + prev2;
        
        
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
            
        }
        return prev;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends