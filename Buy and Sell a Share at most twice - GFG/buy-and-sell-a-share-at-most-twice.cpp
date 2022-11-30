//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int helper(vector<int> price,int idx,int buy,int transaction,vector<vector<vector<int>>> dp)
{
    
    if(transaction == 0)
    {
        return 0;
    }
    
    if(idx == price.size())
    {
        return 0;
    }
    
    if(dp[idx][buy][transaction] != -1)
    {
        return dp[idx][buy][transaction];
    }
    
    int profit=0;
    
    if(buy)
    {
        profit = max( -price[idx] + helper(price,idx+1,0,transaction,dp),helper(price,idx+1,1,transaction,dp));
    }
    else
    {
        profit = max(price[idx] + helper(price,idx+1,1,transaction-1,dp),helper(price,idx+1,0,transaction,dp));
    }
    
    return dp[idx][buy][transaction]=profit;
    
}


int maxProfit(vector<int>&price){
    //Write your code here..
    
    // vector<vector<vector<int>>> dp(price.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
    // return helper(price,0,1,2,dp);
    
    vector<vector<vector<int>>> dp(price.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
    
    for(int idx = price.size() - 1;idx>=0;idx--)
    {
        for(int buy = 0;buy<=1;buy++)
        {
            for(int transaction=1;transaction <= 2;transaction++)
            {
                 int profit=0;
    
                if(buy)
                {
                    profit = max( -price[idx] + dp[idx+1][0][transaction],dp[idx+1][1][transaction]);
                }
                else
                {
                    profit = max(price[idx] + dp[idx+1][1][transaction-1],dp[idx+1][0][transaction]);
                }
                
                dp[idx][buy][transaction]=profit;
            }
        }
        
        
    }
    
    return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends