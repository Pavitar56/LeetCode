//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // long long int helper(int coins[],int idx,int target,vector<vector<long long int>> &dp)
    // {
    //     if(target == 0)
    //     {
    //         return 1;
    //     }
        
    //     if(idx == 0)
    //     {
    //         if(target % coins[idx] == 0)
    //         {
    //             return 1;
    //         }
    //         return 0;
    //     }
        
    //     if(dp[idx][target] != -1)
    //     {
    //         return dp[idx][target];
    //     }
        
    //     long long int notTake = helper(coins,idx-1,target,dp);
    //     long long int take = 0;
    //     if(target >= coins[idx])
    //     {
    //         take = helper(coins,idx,target - coins[idx],dp);
    //     }
        
        
        
    //     return dp[idx][target] = take + notTake; 
        
    // }
  
    long long int count(int coins[], int N, int sum) {

         // code here.
        // vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        // return helper(coins,N-1,sum,dp);
        
       // vector<vector<long long int>> dp(N,vector<long long int>(sum+1,0));
        vector<long long int> prev(sum+1),curr(sum+1);
        
        for(int idx = 0 ;idx < N;idx++)
        {
            curr[0] = 1;
        }
        
        for(int target = 1;target<=sum;target++)
        {
            if(target % coins[0] == 0)
            {
                prev[target] = 1;
            }
            else
            {
                prev[target]=0;
            }
        }
        
        for(int idx = 1 ;idx<N;idx++)
        {
            for(int target = 1;target <=sum ;target++)
            {
                
                long long int notTake = prev[target];
                long long int take = 0;
                
                if(target >= coins[idx])
                {
                    take = curr[target - coins[idx]];
                }
              
                curr[target] = take + notTake; 
         
            }
            prev=curr;
        }
        
        
        
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends