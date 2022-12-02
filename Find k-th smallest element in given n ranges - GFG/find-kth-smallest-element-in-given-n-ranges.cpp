//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(vector<vector<int>>&range, vector<int>queries){
        //Write your code here
        
        
        sort(range.begin(),range.end());
        
        vector<vector<int>> overlap;
        
        overlap.push_back(range[0]);
        
        int i=1;
        while(i < range.size())
        {
            if(overlap.back()[1] >= range[i][0])
            {
                overlap.back()[1] = max(overlap.back()[1],range[i][1]);
            }
            else
            {
                overlap.push_back(range[i]);
            }
            i++;
        
        }
        
        // for(int i=0;i<overlap.size();i++)
        // {
        //     cout<<overlap[i][0]<<" "<<overlap[i][1]<<endl;
        // }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            
            int k = queries[i];
            int count=0;
           // int prev=0;
            
            
            bool flag = false;
            for(int j=0;j<overlap.size();j++)
            {
                count += overlap[j][1] - overlap[j][0] +1;
                
                if(count >= k)
                {
                    //cout<<count<<endl;
                    flag = true;
                    ans.push_back(overlap[j][1] - (count - k));
                    break;
                }
                
               // prev =count;
            }
            
            
            if(flag == false)
            {
                ans.push_back(-1);
            }
            
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(range, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends