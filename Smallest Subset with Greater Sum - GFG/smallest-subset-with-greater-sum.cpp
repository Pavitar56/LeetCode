//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N)
    {
        
        sort(Arr.begin(),Arr.end());
        
        long long int totalSum =0;
        
        for(int i=0;i<N;i++)
        {
            totalSum += Arr[i];
        }
        
        int end = N-1;
        long long int currSum = 0;
        int count =0;
        while(end >= 0)
        {
            currSum += Arr[end];
            count++;
            
            if(currSum > (totalSum - currSum))
            {
                return count;
            }
            end--;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends