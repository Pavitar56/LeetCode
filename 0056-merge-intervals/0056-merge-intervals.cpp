class Solution {
public:
    
    
    bool static compare(vector<int> &v1,vector<int> &v2)
    {
        
        return v1[0] < v2[0] ;
        
    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        
        
        sort(intervals.begin(),intervals.end(),compare);
       
        
        
        
//         int prev =0;
//         int curr = intervals.size();
        
//         while(prev != curr)
//         {
//             vector<vector<int>> ans;
            
//             int si=0;
//             int ei=0;

//             int maximum = intervals[0][1];

//             while(ei < intervals.size())
//             {

//                 if( intervals[ei][0] >= intervals[si][0] && intervals[ei][1] <=intervals[si][1])
//                 {
                      
//                 }
//                 else if(intervals[ei][0] >= intervals[si][0] && intervals[ei][1] >= intervals[si][1]                          && intervals[ei][0] <=intervals[si][1]  )
//                 {
//                     maximum = max(maximum,intervals[ei][1]);
//                 }
//                 else
//                 {

//                     ans.push_back({intervals[si][0],maximum});
//                     si=ei;
//                     maximum = intervals[ei][1];

//                 }
//                 ei++;
//             }
//             ans.push_back({intervals[si][0],maximum});
            
//             intervals = ans;
//             //cout<<prev<<" "<<curr<<endl;
//             prev= curr;
            
//             curr = ans.size();
            
            
            
//         }
//         return intervals;
            
        
        
        vector<vector<int>> ans;
        
        int i=0;
        int j=0;
        
        while(i < intervals.size())
        {
            if(ans.size() == 0)
            {
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0] >= ans[j][0] && intervals[i][0] <= ans[j][1]  // one part in and other outside
                    && intervals[i][1] >= ans[j][1])
            {
                ans[j][1] = intervals[i][1];
            }
            else if(intervals[i][0] >= ans[j][0] && intervals[i][0] <= ans[j][1]   //both parts inside
                   && intervals[i][1] <= ans[j][1])
            {
                i++;                //no need to do anything
                continue;
                    
            }
            else
            {
                ans.push_back(intervals[i]);
                j++;
                
            }
            
            i++;
            
            
        }
        
        return ans;
    }
};