//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        unordered_map<int,int> map;  //key = person,values = how many person knows him
        unordered_map<int,int> map2; //key =person ,value=how many person he knows
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j] == 1)
                {
                    map[j]++;
                    map2[i]++;
                }
                
            }
        }
        
        
        for(auto it = map.begin();it != map.end();it++)
        {
            if(it->second == (n-1) && map2.count(it->first) <=0)
            {
                return it->first;
            }
            
        }
        
        
        return -1;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends