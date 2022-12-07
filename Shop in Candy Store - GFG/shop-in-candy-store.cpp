//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    int minimum(int candies[],int n,int k)
    {
        int start = 0;
        int end = n-1;
        int sum=0;
        
        while(start <= end)
        {
            sum += candies[start];
            
            start++;
            
            end = end -k;
            
            
        }
        
        return sum;
        
    }

    int maximum(int candies[],int n,int k)
    {
        int start = 0;
        int end = n-1;
        int sum =0;
        
        while(start<=end)
        {
            sum += candies[end];
            
            end--;
            start = start + k;
        }
        
        return sum;
    }


    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        
        sort(candies,candies+ N);
        
        vector<int> ans(2,0);
        
        ans[0] = minimum(candies,N,K);
        ans[1] = maximum(candies,N,K);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends