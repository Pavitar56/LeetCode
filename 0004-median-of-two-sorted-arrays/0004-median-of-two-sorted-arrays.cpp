class Solution {
public:
    double findMedianSortedArrays(vector<int>& array1, vector<int>& array2) 
    {
        vector<int> ans;
        
        int i=0;
        int j=0;
        
        while(i<array1.size() && j<array2.size())
        {
            if(array1[i]<=array2[j])
            {
                ans.push_back(array1[i]);
                i++;
            }
            else
            {
                ans.push_back(array2[j]);
                j++;
            }
            
            
        }
        
        while(i<array1.size())
        {
            ans.push_back(array1[i]);
            i++;
        }
        
        while(j<array2.size())
        {
            ans.push_back(array2[j]);
            j++;
        }
        
        if(ans.size()%2 == 0)
        {
            return (ans[ans.size()/2 - 1] + ans[ans.size()/2])/2.0;
        }
        
            return ans[ans.size()/2];
        
        
        
    }
};