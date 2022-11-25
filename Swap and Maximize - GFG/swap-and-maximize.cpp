//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    
    int left = 0;
    int right = n-1;
    
    long long int sum = 0;
    
    while(left < right)
    {
        sum += abs(arr[left] - arr[right]);
        left++;
        right--;
    }
    
    return 2*sum;
}