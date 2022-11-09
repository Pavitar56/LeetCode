class Solution {
public:
    
    
    bool static compare(vector<int> &v1,vector<int> &v2)
    {
        
        return v1[0] < v2[0] ;
        
    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        
        
        sort(intervals.begin(),intervals.end(),compare);
       
        
        
        
        int prev =0;
        int curr = intervals.size();
        
        while(prev != curr)
        {
            vector<vector<int>> ans;
            
            int si=0;
            int ei=0;

            int maximum = intervals[0][1];

            while(ei < intervals.size())
            {

                if( intervals[ei][0] >= intervals[si][0] && intervals[ei][1] <=intervals[si][1])
                {

                }
                else if(intervals[ei][0] >= intervals[si][0] && intervals[ei][1] >= intervals[si][1]                          && intervals[ei][0] <=intervals[si][1]  )
                {
                    maximum = max(maximum,intervals[ei][1]);
                }
                else
                {

                    ans.push_back({intervals[si][0],maximum});
                    si=ei;
                    maximum = intervals[ei][1];

                }
                ei++;
            }
            ans.push_back({intervals[si][0],maximum});
            
            intervals = ans;
            //cout<<prev<<" "<<curr<<endl;
            prev= curr;
            
            curr = ans.size();
            
            
            
        }
        return intervals;
//         vector<vector<int>> finalans;
        
//         ei=ans.size()-1;
//         si=ans.size()-1;
        
//         while(ei >= 0)
//         {
            
//             while(ei >= 0 && ans[si][0] >= ans[ei][0] && ans[si][0] <=ans[ei][1])
//             {
                
//                 ei--;
                
//             }
            
//             finalans.push_back({ans[ei+1][0] , ans[si][1] });
            
//             si=ei;
            
            
//         }
        
        
        
//         return finalans;
        
    }
};