//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) 
{
    
    if(n < m)
    {
        return "No";
    }
    
    unordered_map<int,int> freq1;
    unordered_map<int,int> freq2;
    
    
    for(int i=0;i<n;i++)
    {
        freq1[a1[i]]++;
    }
    
    for(int i=0;i<m;i++)
    {
        freq2[a2[i]]++;
    }
    
    for(auto it = freq2.begin();it != freq2.end();it++)
    {
        if(freq2.count(it->first) > 0)
        {
            
            if(freq2[it->first] > freq1[it->first])
            {
                return "No";
            }
            
        }
        else
        {
            return "No";
        }
        
    }
    
    return "Yes";
    
    
}