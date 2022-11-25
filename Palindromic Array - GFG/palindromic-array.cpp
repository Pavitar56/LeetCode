//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	
    	for(int i=0;i<n;i++)
    	{
    	    int num = a[i];
    	    
    	    string number = to_string(num);
    	    //cout<<number<<endl;
    	    int start=0;
    	    int end = number.size()-1;
    	    
    	    while(start<end)
    	    {
    	        if(number[start] != number[end])
    	        {
    	            return 0;
    	        }
    	        start++;
    	        end--;
    	    }
    	    
    	}
    	
    	return 1;
    	
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
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends