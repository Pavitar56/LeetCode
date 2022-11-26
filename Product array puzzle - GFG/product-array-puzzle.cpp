//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here  
        
        vector<long long int> preProd(n);
        preProd[0] = nums[0];
        
        for(int i=1;i<n;i++)
        {
            preProd[i] = nums[i] * preProd[i-1];
           // cout<<preProd[i]<<" ";
        }
       // cout<<endl;
        vector<long long int> sufProd(n);
        sufProd[n-1] = nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            sufProd[i] = nums[i] * sufProd[i+1];
           // cout<<sufProd[i]<<" ";
        }
      //  cout<<endl;
        vector<long long int> P(n);
        
        for(int i=0;i<n;i++)
        {
            long long int pre = 1;
            if(i>0)
            {
                pre = preProd[i-1];
            }
            long long int suff = 1;
            if(i < (n-1))
            {
                suff = sufProd[i+1];
            }
            
            P[i] = pre * suff;
        }
        
        return P;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends