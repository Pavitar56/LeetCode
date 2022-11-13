class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        
//         int i=0;
//         int j=0;
//         int m= nums1.size();
//         int n = nums2.size();
        
//         vector<vector<int>> ans;
        
//         while(i<nums1.size() && j< nums2.size())
//         {
//             ans.push_back({nums1[i],nums2[j]});
//             k--;
            
//             if(k == 0)
//             {
//                 break;
//             }
            
//             if((i+1)<m && (j+1)<n)
//             {
//                 if(nums1[i+1]<nums2[j+1])
//                 {
//                     i++;
//                 }
//                 else
//                 {
//                     j++;
//                 }
//             }
//             else if((i+1)>=m)
//             {
//                 i=0;
//                 j++;
//             }
//             else
//             {
//                 j=0;
//                 i++;
//             }
            
            
            
//         }
        
        
        
//         return ans;
        
        
        
        //{sum,{1st,2nd}}
        
        priority_queue<pair<int,pair<int,int>>> pq;
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum = nums1[i] + nums2[j];
                if(pq.size()<k)
                {
                    pq.push({ sum ,{nums1[i],nums2[j]}});
                
                }
                else if(sum < pq.top().first)
                {
                    pq.pop();
                    pq.push({ sum ,{nums1[i],nums2[j]}});
                }
                else     //means sum >= pq.top which means we dont need to travel rest of  2nd vector
                {
                    break;
                }
              
            }
        
        }
        
        
        vector<vector<int>> ans;
        
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        
        return ans;
    }
};