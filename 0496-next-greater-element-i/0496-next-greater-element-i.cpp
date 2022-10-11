class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        
//         vector<int> ans(nums1.size(),-1);
        
//         for(int i=0;i<nums1.size();i++)
//         {
//             for(int j=0;j<nums2.size();j++)
//             {
//                 if(nums1[i] == nums2[j])
//                 {
//                     ans[i] = j;
//                     break;
//                 }
                
//             }
//         }
        
        
//         for(int i=0;i<ans.size();i++)
//         {
//             int nextGreater = -1;
//             for(int j = ans[i] + 1 ; j < nums2.size();j++)
//             {
//                 if(nums2[j] > nums2[ans[i]])
//                 {
//                     nextGreater = nums2[j];
//                     break;
//                 }
//             }
            
//             ans[i] = nextGreater;
//         }
        
//         return ans;
        
         stack<int>st;
        unordered_map<int,int>mp; //we will be using map as nextgrt array
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            
            if(st.empty())
                mp[nums2[i]]=-1;
            else
                mp[nums2[i]]=st.top();
        
            st.push(nums2[i]);
        }
        //matching and putting value in output vector
        vector<int> out;
        for(int i=0;i<nums1.size();i++)
        {
            out.push_back(mp[nums1[i]]);
        }
        return out;
        
    }
};