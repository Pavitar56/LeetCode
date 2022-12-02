//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector <int>> &matrix, int N, int M, int target)
	{
	    // your code here
	    
	     int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            
            int start = 0;
            int end = n-1;
                
            while(start<=end)
            {
                int mid = start + (end-start)/2;
                
                if(target == matrix[i][mid])
                {
                    return true;
                }
                else if(target < matrix[i][mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid+1;
                }
                    
                    
            }
      
        }
        
        return false;
	    
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends