//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &nums, int n ) {
        //code here
        
        
        int k=0;
        vector<long long int> subSum(nums.size(),0);
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            subSum[i]=sum;
        }
        
        unordered_map<long long int,long long int> map;
        int ans=0;
        for(int i=0;i<subSum.size();i++)
        {
            if(subSum[i] == k)
            {
                ans++;
            }
            
            if(map.count(subSum[i] - k)>0)
            {
                ans += map[subSum[i] - k];
            }
            map[subSum[i]]++;
            
            
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends